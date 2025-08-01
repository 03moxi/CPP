#include <func.h>
int main(int argc, char *argv[])
{
    // ./13_redirect file1
    ARGS_CHECK(argc,2);
    int fd1 = open(argv[1],O_RDWR);
    ERROR_CHECK(fd1,-1,"open");
    printf("You can see me!\n");
    close(STDOUT_FILENO);
    int fd2 = dup(fd1);
    printf("fd2 = %d\n", fd2);
    printf("You can't see me!\n");
    return 0;
}
