#include <func.h>
typedef struct train_s {
    int length;
    char data[1000];
} train_t;
int main(int argc, char *argv[])
{
    // ./2_B 1.pipe
    ARGS_CHECK(argc,2);
    int fdr_pipe = open(argv[1],O_RDONLY);
    ERROR_CHECK(fdr_pipe,-1,"open");

    train_t train;
    read(fdr_pipe,&train.length,sizeof(train.length));
    read(fdr_pipe,train.data,train.length);
    char filename[4096] = {0};
    memcpy(filename,train.data,train.length);
    char path[8192] = {0};
    char dir[] = "dir1/";
    mkdir(dir,0777);
    sprintf(path,"%s%s%s",dir,"/",filename);
    int fdw_file = open(path,O_RDWR|O_CREAT|O_TRUNC,0666);
    ERROR_CHECK(fdw_file,-1,"open");
    read(fdr_pipe,&train.length,sizeof(train.length));
    read(fdr_pipe,train.data,train.length);
    write(fdw_file,train.data,train.length);
    
    close(fdw_file);
    close(fdr_pipe);
    return 0;
}

