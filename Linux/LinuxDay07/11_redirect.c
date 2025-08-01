#include <func.h>
int main(int argc, char *argv[])
{
    // ./11_redirect file1
    ARGS_CHECK(argc,2);
    printf("You can see me!\n");
    // 隐藏要求 close之前先打印一个换行
    close(STDOUT_FILENO); // STDOUT_FILENO 1
    int fd = open(argv[1],O_RDWR);
    ERROR_CHECK(fd,-1,"open");
    printf("fd = %d\n", fd);
    printf("You can't see me!\n");
    return 0;
}
