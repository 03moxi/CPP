#include <func.h>
int main(int argc, char *argv[])
{
    // ./2_homework_file1 file1
    ARGS_CHECK(argc,2);
    int fd = open(argv[1],O_WRONLY|O_TRUNC|O_CREAT,0666);
    //char ch = '1';
    char buf[10000];
    memset(buf,'1',sizeof(buf));
    for(int i = 0; i < 100; ++i){
        //write(fd,&ch,1);
        write(fd,buf,sizeof(buf));
    }
    close(fd);
    return 0;
}

