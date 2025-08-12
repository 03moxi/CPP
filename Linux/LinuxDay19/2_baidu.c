#include <func.h>

int main(int argc,char*argv[])
{
    const char query[] = "GET / HTTP/1.0\r\n"
                         "Host: www.baidu.com\r\n"
                         "\r\n";
    const char hostname[] = "www.baidu.com";
    //获取主机的 IP 地址。该函数返回一个 hostent 结构体，包含了该主机的所有 IP 地址。
    //如果 gethostbyname 返回 NULL，表示解析主机名失败，程序会输出错误信息并返回 -1。
    struct hostent *entry = gethostbyname(hostname);
    if(entry == NULL){
        herror("gethostbyname");
        return -1;
    }
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(80);
    memcpy(&addr.sin_addr,entry->h_addr_list[0],sizeof(addr.sin_addr));
    
    int sockfd = socket(AF_INET,SOCK_STREAM,0);
    connect(sockfd,(struct sockaddr *)&addr,sizeof(addr));

    send(sockfd,query,strlen(query),0);

    char buf[4096];
    while(1){
        bzero(buf,sizeof(buf));
        ssize_t ret = recv(sockfd,buf,sizeof(buf),0);
        if(ret == 0){
            break;
        }
        printf("ret = %ld\n, buf = %s\n", ret, buf);
    }
    return 0;
}

