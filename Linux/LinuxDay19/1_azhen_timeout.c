#include <func.h>
typedef struct Conn_s {
    int isConnected; // 0 未连接 1 已经连接
    int netfd;
    time_t lastActive;
} Conn_t;

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
                         sizeof(serverAddr));
    ERROR_CHECK(ret,-1,"setscokopt");
    
    ret = bind(sockfd,(struct sockaddr *)&serverAddr,sizeof(serverAddr));
    ERROR_CHECK(ret,-1,"bind");
    listen(sockfd,50);
    
    fd_set monitorSet;
    fd_set readySet;
    FD_ZERO(&monitorSet);
    FD_SET(sockfd,&monitorSet);
    Conn_t client[1024];
    for(int i =0;i<1024;i++){
        client[i].isConnected = 0;
    }
    int curidx = 0; // 下一次加入的netfd的下标
    // 用于查找的哈希表 netfd --> idx
    int fdToidx[1024];
    for(int i=0;i<1024;i++){
        fdToidx[i] = -1;
    }
    time_t now;
    char buf[4096];
    while(1){
        memcpy(&readySet,&monitorSet,sizeof(fd_set));
        struct timeval timeout;
        timeout.tv_sec = 10;
        timeout.tv_usec = 0;
        select(1024,&readySet,NULL,NULL,&timeout);
        now = time(NULL);
        printf("now = %s\n",ctime(&now));
        if(FD_ISSET(sockfd,&readySet))   // 有新的客户端建立连接
        {
            // accept创建新的netfd，将其信息插入到client
            client[curidx].isConnected = 1;
            client[curidx].netfd = accept(sockfd,NULL,NULL);
            client[curidx].lastActive = time(NULL);
            printf("i = %d, netfd = %d, now = %s\n",curidx,client[curidx].netfd,ctime(&client[curidx].lastActive));
            fdToidx[client[curidx].netfd] = curidx;
            // 加入到监听结合
            FD_SET(client[curidx].netfd,&monitorSet);
            ++curidx;
        }
        // 在select返回之后，只能遍历所有的netfd，看是否就绪
        for(int i=0;i<curidx;++i){
            // 在线 & 发了消息
            if(client[i].isConnected == 1 && FD_ISSET(client[i].netfd,&readySet))
            {
                memset(buf,0,sizeof(buf));
                ssize_t sret = recv(client[i].netfd,buf,sizeof(buf),0);
                if(sret == 0)
                {
                    FD_CLR(client[i].netfd,&monitorSet);
                    close(client[i].netfd);
                    fdToidx[client[i].netfd] = -1;
                    client[i].isConnected = 0;
                    continue;
                }
                client[i].lastActive = time(NULL);
                printf("i = %d, netfd = %d, now = %s\n", i, client[i].netfd, ctime(&client[i].lastActive));
                // 转发
                for(int j=0;j<curidx;++j){
                    if(client[j].isConnected == 1 && j != i)// 在线 & 不是自己
                    {
                        send(client[j].netfd,buf,strlen(buf),0);
                    }
                }
            }     
        }
        for(int i = 0; i < curidx; ++i){
            if(client[i].isConnected == 1 && now - client[i].lastActive > 5){
               FD_CLR(client[i].netfd,&monitorSet);
               close(client[i].netfd);
               fdToidx[client[i].netfd] = -1;
               client[i].isConnected = 0;
            }
        }
    }
    return 0;
}

