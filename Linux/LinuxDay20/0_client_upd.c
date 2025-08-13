#include <func.h>

int main(int argc,char*argv[])
{
    ARGS_CHECK(argc,3);
    int sockfd = socket(AF_INET,SOCK_DGRAM,0);
    struct sockaddr_in serveraddr;
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(atoi(argv[2]));
    serveraddr.sin_addr.s_addr = inet_addr(argv[1]);

    sendto(sockfd,"hello",5,0,(struct sockaddr *)&serveraddr,sizeof(serveraddr));
    char buf[4096] = {0};
    sleep(1);
    recvfrom(sockfd,buf,1,0,NULL,NULL);
    printf("buf = %s\n", buf);
    sleep(1);
    recvfrom(sockfd,buf,4096,0,NULL,NULL);
    printf("buf = %s\n", buf);
    return 0;
}

