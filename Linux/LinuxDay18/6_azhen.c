#include <func.h>

int main(int argc,char*argv[])
{
    ARGS_CHECK(argc,3);
    int sockfd = socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(atoi(argv[2]));
    serverAddr.sin_addr.s_addr = inet_addr(argv[1]);
    
    int reuse = 1;
    int ret = setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&reuse,sizeof(reuse));
    ERROR_CHECK(ret,-1,"setsockopt");
    ret = bind(sockfd,(struct sockaddr *)&serverAddr,sizeof(serverAddr));
    ERROR_CHECK(ret,-1,"bind");
    listen(sockfd,50);
    
    fd_set monitorSet; // 监听集合
    fd_set readySet; // 就绪集合
    FD_ZERO(&monitorSet);
    FD_SET(sockfd,&monitorSet);
    char buf[4096] = {0};
    int netfd = -1; //netfd为-1时，阿强不存在
    while(1){
        memcpy(&readySet,&monitorSet,sizeof(monitorSet));
        select(20,&readySet,NULL,NULL,NULL);
        if(FD_ISSET(sockfd,&readySet)){
            netfd = accept(sockfd,NULL,NULL);
            printf("aqiang is connected!\n");
            FD_CLR(sockfd,&monitorSet);
            FD_SET(STDIN_FILENO,&monitorSet);
            FD_SET(netfd,&monitorSet);
        }
        if(netfd != -1 && FD_ISSET(STDIN_FILENO,&readySet)){
            memset(buf,0,sizeof(buf));
            int cout  = read(STDIN_FILENO,buf,sizeof(buf));
            if(cout == 0){
                // 阿强断开了
                FD_SET(sockfd,&monitorSet);
                FD_CLR(STDIN_FILENO,&monitorSet);
                FD_CLR(netfd,&monitorSet);
                close(netfd);
                netfd = -1;
                printf("wohuihaohaode\n");
                continue;
            }
            send(netfd,buf,strlen(buf),0);
        }
        if(netfd != -1 && FD_ISSET(netfd,&readySet)){
            memset(buf,0,sizeof(buf));
            int cout = read(netfd,buf,sizeof(buf));
            if(cout == 0){
                //阿珍想踢走阿强
                FD_SET(sockfd,&monitorSet);
                FD_CLR(STDIN_FILENO,&monitorSet);
                FD_CLR(netfd,&monitorSet);
                close(netfd);
                netfd = -1;
                printf("nishigehaoren\n");
                continue;
            }
            printf("aqaing : %s\n",buf);
        }
    }
    return 0;
}

