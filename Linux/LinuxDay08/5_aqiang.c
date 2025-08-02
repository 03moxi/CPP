#include <func.h>
int main(int argc, char *argv[])
{
    // ./5_aqiang 1.pipe 2.pipe
    ARGS_CHECK(argc,3);
    int fdr = open(argv[1],O_RDONLY);
    ERROR_CHECK(fdr,-1,"open read");
    int fdw = open(argv[2],O_WRONLY);
    ERROR_CHECK(fdw,-1,"open write");
    printf("aqiang is connected!\n");
    char buf[4096];
    while(1){
        // 读取stdin的数据
        memset(buf,0,sizeof(buf));
        read(STDIN_FILENO,buf,sizeof(buf));
        write(fdw,buf,strlen(buf));
        // 读取阿珍的消息
        memset(buf,0,sizeof(buf));
        read(fdr,buf,sizeof(buf));
        printf("buf = %s\n", buf);
    }
    return 0;
}
