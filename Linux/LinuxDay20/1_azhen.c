#include <func.h>

int main(int argc,char*argv[])
{
    ARGS_CHECK(argc,3);
    int sockfd = socket(AF_INET,SOCK_DGRAM,0);
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(atoi(argv[2]));
    serverAddr.sin_addr.s_addr = inet_addr(argv[1]);

    int ret = bind(sockfd,(struct sockaddr *)&serverAddr,sizeof(serverAddr));
    ERROR_CHECK(ret,-1,"bind");

    struct sockaddr_in clientAddr;
    socklen_t socklen = sizeof(clientAddr);
    char buf[4096];
    recvfrom(sockfd,buf,4096,0,
             (struct sockaddr *)&clientAddr,&socklen);
    printf("buf = %s, ip = %s, port = %d\n",
           buf,inet_ntoa(clientAddr.sin_addr),ntohs(clientAddr.sin_port));
    fd_set rdset;
    while(1){
        FD_ZERO(&rdset);
        FD_SET(sockfd,&rdset);
        FD_SET(STDIN_FILENO,&rdset);
        select(sockfd+1,&rdset,NULL,NULL,NULL);
        if(FD_ISSET(STDIN_FILENO,&rdset)){
            bzero(buf,sizeof(buf));
            ret = read(STDIN_FILENO,buf,sizeof(buf));
            if(ret == 0){
                break;
            }
            sendto(sockfd,buf,strlen(buf),0,
                   (struct sockaddr *)&clientAddr,sizeof(clientAddr));
        }
        if(FD_ISSET(sockfd,&rdset)){
            bzero(buf,sizeof(buf));
            ret = recvfrom(sockfd,buf,sizeof(buf),0,NULL,NULL);
            if(ret == 0){
                break;
            }
            printf("aqaing : %s\n",buf);
        }
    }
    return 0;
}

