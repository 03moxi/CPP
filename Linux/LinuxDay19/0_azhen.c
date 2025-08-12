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
    int ret = setsockopt(sockfd,SOL_SOCKET,
                         SO_REUSEADDR,&reuse,
                         sizeof(reuse));
    ERROR_CHECK(ret,-1,"setsockopt");
    ret = bind(sockfd,(struct sockaddr *)&serverAddr,sizeof(serverAddr));
    listen(sockfd,50);
    
    fd_set monitorSet;
    fd_set readySet;
    FD_ZERO(&monitorSet);
    FD_SET(sockfd,&monitorSet);
    // 设计一个数据结构 存储所有客户端的netfd
    int netfd[1024];
    for(int i=0;i<1024;i++){
        netfd[i] = -1;
    }
    int curidx = 0; // 下一次加入的netfd的下标
    // 用于查找的哈希表 netfd --> idx
    int fdToidx[1024];
    for(int i=0;i<1024;i++){
        fdToidx[i] = -1;
    }
    char buf[4096];
    while(1){
        memcpy(&readySet,&monitorSet,sizeof(fd_set));
        select(1024,&readySet,NULL,NULL,NULL);
        if(FD_ISSET(sockfd,&readySet)){
            netfd[curidx] = accept(sockfd,NULL,NULL);
            printf("i = %d, netfd = %d\n", curidx, netfd[curidx]);
            fdToidx[netfd[curidx]] = curidx;
            FD_SET(netfd[curidx],&monitorSet);
            ++curidx;
        }
        for(int i=0;i<curidx;i++){
            if(netfd[i] != -1 && FD_ISSET(netfd[i],&readySet)){
                memset(buf,0,sizeof(buf));
                int sret = recv(netfd[i],buf,sizeof(buf),0);
                if(sret == 0){
                    // 某个客户端断开连接
                    FD_CLR(netfd[i],&monitorSet);
                    close(netfd[i]);
                    fdToidx[netfd[i]] = -1;
                    netfd[i] = -1;
                    continue;
                }
                for(int j=0;j<curidx;j++){
                    if(netfd[j] != -1 && j != i){
                        send(netfd[j],buf,strlen(buf),0);
                    }
                }
            }
        }
    }
    return 0;
}

