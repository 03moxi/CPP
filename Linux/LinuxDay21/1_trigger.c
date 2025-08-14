#include <func.h>
int main(int argc, char *argv[])
{
    ARGS_CHECK(argc,3);
    int sockfd = socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(atoi(argv[2]));
    serverAddr.sin_addr.s_addr = inet_addr(argv[1]);
    int reuse = 1; //允许重用
    int ret = setsockopt(sockfd,SOL_SOCKET,
                         SO_REUSEADDR,&reuse,sizeof(reuse));
    ERROR_CHECK(ret,-1,"setsockopt");
    ret = bind(sockfd,(struct sockaddr *)&serverAddr,sizeof(serverAddr));
    ERROR_CHECK(ret,-1,"bind");
    listen(sockfd,50);
    int netfd = accept(sockfd,NULL,NULL);
    
    // fd_set rdset; epoll_create
    int epfd = epoll_create(1); // 创建epoll文件对象
    // 设置监听
    struct epoll_event events; // 什么情况就绪？ 就绪了怎么办？
    events.events = EPOLLIN; // 读就绪
    events.data.fd = STDIN_FILENO; // 就绪之后放入STDIN_FILENO
    epoll_ctl(epfd,EPOLL_CTL_ADD,STDIN_FILENO,&events);
    events.events = EPOLLIN|EPOLLET; // 边缘触发 edge-triggered
    events.data.fd = netfd; // 就绪之后放入netfd
    epoll_ctl(epfd,EPOLL_CTL_ADD,netfd,&events);
    char buf[3] = {0};
    while(1){
        struct epoll_event readySet[2];
        int readyNum = epoll_wait(epfd,readySet,2,-1);
        printf("epoll_wait ready!\n");
        for(int i = 0; i < readyNum; ++i){
            if(readySet[i].data.fd == STDIN_FILENO){
                bzero(buf,sizeof(buf));
                read(STDIN_FILENO,buf,sizeof(buf));
                send(netfd,buf,strlen(buf),0);
            }
            else if(readySet[i].data.fd == netfd){
                bzero(buf,sizeof(buf));
                while(1){
                    ssize_t sret = recv(netfd,buf,2,MSG_DONTWAIT);
                    if(sret == -1 || sret == 0){
                        // sret 为 -1 缓冲区读完了
                        // sret 为 0 客户端断开:
                        break;
                    }
                    printf("buf = %s\n", buf);
                }
            }
        }
        //if(FD_ISSET(STDIN_FILENO,&rdset)){
        //    bzero(buf,sizeof(buf));
        //    read(STDIN_FILENO,buf,sizeof(buf));
        //    send(netfd,buf,strlen(buf),0);
        //}
        //if(FD_ISSET(netfd,&rdset)){
        //    bzero(buf,sizeof(buf));
        //    recv(netfd,buf,sizeof(buf),0);
        //    printf("buf = %s\n", buf);
        //}
    }
    return 0;
}


