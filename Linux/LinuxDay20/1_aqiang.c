#include <func.h>

int main(int argc,char*argv[])
{
    int sockfd = socket(AF_INET,SOCK_DGRAM,0);
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(atoi(argv[2]));
    serverAddr.sin_addr.s_addr = inet_addr(argv[1]);

    char buf[4096] = {0};
    sendto(sockfd,"hello",5,0,
           (struct sockaddr *)&serverAddr,sizeof(serverAddr));
    
    fd_set rdset;
    while(1){
        FD_ZERO(&rdset);
        FD_SET(sockfd,&rdset);
        FD_SET(STDIN_FILENO,&rdset);
        select(sockfd+1,&rdset,NULL,NULL,NULL);
        if(FD_ISSET(STDIN_FILENO,&rdset)){
            bzero(buf,sizeof(buf));
            int ret = read(STDIN_FILENO,buf,sizeof(buf));
            if(ret == 0){
                break;
            }
            sendto(sockfd,buf,strlen(buf),0,
                   (struct sockaddr *)&serverAddr,sizeof(serverAddr));
        }
        if(FD_ISSET(sockfd,&rdset)){
            bzero(buf,sizeof(buf));
            int ret = read(sockfd,buf,sizeof(buf));
            if(ret == 0){
                break;
            }
            printf("azhen : %s\n",buf);
        }
    }
    return 0;
}

