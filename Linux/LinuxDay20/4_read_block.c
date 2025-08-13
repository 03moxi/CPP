#include <func.h>

int SetNonblock(int fd){
    int flag = fcntl(fd,F_GETFL);
    flag = flag|O_NONBLOCK;
    int ret = fcntl(fd,F_SETFL,flag);
    ERROR_CHECK(ret,-1,"fcntl");
    return 0;
}


int main(int argc,char*argv[])
{
    int fd = open("1.pipe",O_RDWR);
    SetNonblock(fd);
    char buf[3] = {0};
    while(1){
        bzero(buf,3);
        ssize_t sret = read(fd,buf,2);
        printf("sret = %ld, buf = %s\n", sret, buf);
        sleep(1);
    }
    return 0;
}

