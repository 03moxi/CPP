#include <func.h>
int main(int argc, char *argv[])
{
    // ./16_close_read 1.pipe
    ARGS_CHECK(argc,2);
    int fdr = open(argv[1], O_RDONLY);
    ERROR_CHECK(fdr,-1,"open");
    printf("read side is opened!\n");
    //sleep(5);
    //printf("sleep over!\n");
    //char buf[1024] = {0};
    //ssize_t sret = read(fdr, buf, sizeof(buf));
    //printf("sret = %ld, buf = %s\n", sret, buf);
    close(fdr);
    printf("read side is closed!\n");
    return 0;
}

