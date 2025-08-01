#include <func.h>
int main(int argc, char *argv[])
{
    // ./16_close_write 1.pipe
    ARGS_CHECK(argc,2);
    int fdw = open(argv[1], O_WRONLY);
    ERROR_CHECK(fdw,-1,"open");
    //printf("write side is opened!\n");
    //close(fdw);
    //printf("write side is closed!\n");
    sleep(5);
    printf("sleep over!\n");
    ssize_t sret = write(fdw,"hello",5);
    printf("sret = %ld\n", sret);
    return 0;
}
