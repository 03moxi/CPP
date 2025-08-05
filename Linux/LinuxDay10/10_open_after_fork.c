#include <func.h>
int main(int argc, char *argv[])
{
    // ./10_fork_share file1
    ARGS_CHECK(argc,2);
    if(fork()){
        int fd = open(argv[1],O_RDWR);
        ERROR_CHECK(fd,-1,"open");
        sleep(1);
        write(fd,"world",5);
    }
    else{
        int fd = open(argv[1],O_RDWR);
        ERROR_CHECK(fd,-1,"open");
        write(fd,"hello",5);
    }
    return 0;
}
