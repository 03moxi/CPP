#include <func.h>
int main(int argc, char *argv[])
{
    // ./2_binary_write file3
    ARGS_CHECK(argc,2);
    int fd = open(argv[1],O_RDWR);
    ERROR_CHECK(fd,-1,"open");
    
    int i = 1000000;
    write(fd,&i,sizeof(i));
    close(fd);
    return 0;
}
