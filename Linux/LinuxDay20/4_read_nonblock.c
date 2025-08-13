#include <func.h>
int main(int argc, char *argv[])
{
    int fd = open("file1",O_RDWR);
    char buf[3] = {0};
    while(1){
        bzero(buf,3);
        ssize_t sret = read(fd,buf,2);
        printf("sret = %ld, buf = %s\n", sret, buf);
        if(sret == 0){
            break;
        }
        //sleep(1);
    }
    return 0;
}


