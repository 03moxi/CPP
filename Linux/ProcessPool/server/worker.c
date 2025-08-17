#include "head.h"

int makeWorker(int workerNum,workerdata_t* workerArr){
    for(int i=0;i<workerNum;++i){
        int pipefd[2];
        socketpair(AF_LOCAL,SOCK_STREAM,0,pipefd);
        pid_t pid = fork();
        if(pid == 0){
            close(pipefd[1]);
            workLoop(pipefd[0]);
            //希望子进程永远脱离不了这个if结构
        }
        close(pipefd[0]);
        workerArr[i].status = FALS;
        workerArr[i].pid = pid; //父进程调用fork 获取了创建的子进程的pid
        workerArr[i].pipesockfd = pipefd[1];
        printf("i = %d, pid = %d, pipefd = %d\n", i, pid, pipefd[1]);
    }
    return 0;
}

int workLoop(int sockfd){
    while(1){
        int netfd;
        int exitFlag;
        recvfd(sockfd,&netfd,&exitFlag); // 接收任务
        if(exitFlag == 1){
            printf("I am going to exit!\n");
            exit(0);
        }
        printf("begin work!\n"); // 执行任务
        //sleep(10);
        transFile(netfd);
        close(netfd);
        printf("work over!\n");
        // 任务完成之后，向主人进程发送自己pid
        pid_t pid = getpid();
        send(sockfd,&pid,sizeof(pid),0);
    }
    return 0;
}
