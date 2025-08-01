#include <func.h>
int main(int argc, char *argv[])
{
    // ./12_dup file1
    ARGS_CHECK(argc,2);
    int oldfd = open(argv[1], O_RDWR);
    ERROR_CHECK(oldfd,-1,"open");
    printf("oldfd = %d\n", oldfd);
    int newfd = dup(oldfd);
    printf("newfd = %d\n", newfd);

    write(oldfd,"Hello",5);
    write(newfd,"World",5);
    return 0;
}

