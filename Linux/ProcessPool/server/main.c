#include "head.h"
int exitPipe[2];
void handler(int signum){

    printf("signum = %d\n", signum);
    write(exitPipe[1],"1",1);
}

int main(int argc,char*argv[])
{
    // ./server 192.168.100.104 1234 3
    ARGS_CHECK(argc,4);
    int workerNum = atoi(argv[3]);
    workerdata_t* workerArr = (workerdata_t *)calloc(workerNum,sizeof(workerdata_t));
    // 创建了子进程 获取每个子进程的状态
    makeWorker(workerNum,workerArr);
    // 创建一个自己和自己通信的管道
    pipe(exitPipe);
    signal(SIGUSR1,handler);
    int sockfd;
    // 初始化tcp服务端
    tcpInit(argv[1],argv[2],&sockfd);
    // 初始化epoll
    int epfd = epoll_create(1);
    epollAdd(epfd,sockfd);
    // 监听每个子进程的pipesockfd
    for(int i = 0; i < workerNum; ++i){
        epollAdd(epfd, workerArr[i].pipesockfd);
    }
    epollAdd(epfd,exitPipe[0]);
    while(1){
        struct epoll_event readySet[1024];
        int readyNum = epoll_wait(epfd,readySet,1024,-1);
        for(int i=0;i<readyNum;++i){
            if(readySet[i].data.fd == sockfd){
                int netfd = accept(sockfd,NULL,NULL);
                printf("1 client is connected!\n");
                // 顺序查找一个空闲的子进程
                for(int j=0;j<workerNum;++j){
                    if(workerArr[j].status == FALS){
                        sendfd(workerArr[j].pipesockfd,netfd,0);
                        workerArr[j].status = BUSY;
                        break;
                    }
                }
                close(netfd);
            }
            else if(readySet[i].data.fd == exitPipe[0]){
                // 进程池要退出了
                for(int j=0;j<workerNum;++j){
                    //kill(workerArr[j].pid,SIGKILL);
                    //sendfd的第3个参数，表示子进程要退出
                    sendfd(workerArr[j].pipesockfd,0,1);
                    printf("Kill 1 worker!\n");
                }
                for(int j=0;j<workerNum;++j){
                    wait(NULL);
                }
                printf("All workers are killed!\n");
                exit(0);
            }
            else{
                // 某个子进程完成任务了
                int pipesockfd = readySet[i].data.fd;
                // 使用顺序查找从fd找到是几号工人进程
                for(int j=0;j<workerNum;++j){
                    if(workerArr[j].pipesockfd == pipesockfd){
                        pid_t pid;
                        recv(pipesockfd,&pid,sizeof(pid),0);
                        printf("%d worker, pid = %d\n", j, pid);
                        workerArr[j].status = FALS;
                        break;
                    }
                }
            }
        }
    }
    return 0;
}

