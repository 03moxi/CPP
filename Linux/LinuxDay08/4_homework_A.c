#include <func.h>
int main(int argc, char *argv[])
{
    // ./4_homework_A 1.pipe
    ARGS_CHECK(argc,2);
    int fdw = open(argv[1],O_WRONLY);

    printf("Hello world 1\n");
    int backupfd = 10;
    dup2(STDOUT_FILENO,backupfd);
    dup2(fdw,STDOUT_FILENO);
    printf("Hello world 2\n");
    dup2(backupfd,STDOUT_FILENO);
    printf("Hello world 3\n");
    return 0;
}

