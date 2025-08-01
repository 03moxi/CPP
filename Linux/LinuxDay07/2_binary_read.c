#include <func.h>
int main(int argc, char *argv[])
{
    // ./2_binary_read file3
    ARGS_CHECK(argc,2);
    int fd = open(argv[1],O_RDWR);
    ERROR_CHECK(fd,-1,"open");
    
    int i;
    read(fd,&i,sizeof(i));
    printf("i = %d\n", i);
    close(fd);
    return 0;
}
