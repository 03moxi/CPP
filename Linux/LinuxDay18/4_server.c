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
    int ret = bind(sockfd,(struct sockaddr *)&serverAddr,sizeof(serverAddr));
    ERROR_CHECK(ret,-1,"bind");
    listen(sockfd,50);
    // sockfd 是监听socket的文件描述符
    struct sockaddr_in clientAddr;
    socklen_t socklen = sizeof(clientAddr);
    // socklen 必须赋初值
    int netfd = accept(sockfd,(struct sockaddr *)&clientAddr,&socklen);
    printf("client ip = %s, port = %d\n",
           inet_ntoa(clientAddr.sin_addr),
           ntohs(clientAddr.sin_port));
    char buf[4096] = {0};
    ssize_t sret = recv(netfd,buf,sizeof(buf),0);
    printf("sret = %ld, buf = %s\n", sret, buf);
    send(netfd,"howareyou",9,0);
    return 0;
}

