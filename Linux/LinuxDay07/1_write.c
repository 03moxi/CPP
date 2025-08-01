#include <func.h>
int main(int argc, char *argv[])
{
    // ./1_write file1
    ARGS_CHECK(argc,2);
    int fd = open(argv[1],O_RDWR);
    ERROR_CHECK(fd,-1,"open");
    ssize_t sret = write(fd,"howareyou",9);
    printf("sret = %ld\n", sret);
    close(fd);
    return 0;
}
