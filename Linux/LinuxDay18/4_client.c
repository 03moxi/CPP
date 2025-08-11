#include <func.h>

int main(int argc,char*argv[])
{
    // ./4_server 192.168.159.128 1234
    // 192.168.159.128:1234 是服务端的ip端口
    ARGS_CHECK(argc,3);
    int sockfd = socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(atoi(argv[2]));
    serverAddr.sin_addr.s_addr = inet_addr(argv[1]);
    int ret = connect(sockfd,(struct sockaddr *)&serverAddr,sizeof(serverAddr));
    ERROR_CHECK(ret,-1,"connect");
    
    send(sockfd,"hello",5,0);
    send(sockfd,"world",5,0);
    char buf[4096] = {0};
    ssize_t sret = read(sockfd,buf,sizeof(buf));
    printf("sret = %ld, buf = %s\n",sret,buf);

    return 0;
}

