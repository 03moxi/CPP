#include <func.h>
typedef struct train_s {
    int length;
    char data[1000];
} train_t;
int main(int argc, char *argv[])
{
    // ./2_A 1.pipe file
    ARGS_CHECK(argc,3);
    int fdw_pipe = open(argv[1],O_WRONLY);
    ERROR_CHECK(fdw_pipe,-1,"open");
    
    train_t train;
    train.length = strlen(argv[2]);
    memcpy(train.data,argv[2],train.length);
    // 发送文件名
    write(fdw_pipe,&train.length,sizeof(train.length));
    write(fdw_pipe,train.data,train.length);

    // 发送文件内容
    int fdr_file = open(argv[2],O_RDONLY);
    ERROR_CHECK(fdr_file,-1,"open");
    ssize_t sret = read(fdr_file,train.data,sizeof(train.data));
    train.length = sret;
    write(fdw_pipe,&train.length,sizeof(train.length));
    write(fdw_pipe,train.data,train.length);

    close(fdr_file);
    close(fdw_pipe);
    return 0;
}
