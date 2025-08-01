#include <func.h>
int main(int argc, char *argv[])
{
    // ./14_redirect file1 
    ARGS_CHECK(argc,2);
    int fd = open(argv[1],O_RDWR);
    ERROR_CHECK(fd,-1,"open");

    printf("我过来啦！\n");
    int backupfd = 10;
    dup2(STDOUT_FILENO,backupfd);
    dup2(fd,STDOUT_FILENO);
    printf("我过去啦！\n");
    dup2(backupfd,STDOUT_FILENO);
    printf("我又过来啦！\n");
    return 0;
}
