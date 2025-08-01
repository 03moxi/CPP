#include <func.h>
int main(int argc, char *argv[])
{
    // ./3_mycp src dest
    ARGS_CHECK(argc,3);
    int fdr = open(argv[1],O_RDONLY);
    ERROR_CHECK(fdr, -1, "open read");
    int fdw = open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,0666);
    ERROR_CHECK(fdw, -1, "open write");

    char buf[1024*1024*4] = {0}; // 使用char数组的原因是方便控制内存大小
    while(1){
        memset(buf,0,sizeof(buf));
        ssize_t sret = read(fdr,buf,sizeof(buf));
        if(sret == 0){
            break;
        }
        write(fdw,buf,sret);
    }

    close(fdr);
    close(fdw);
    return 0;
}
