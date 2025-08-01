#include <func.h>
int main(int argc, char *argv[])
{
    // ./2_text file2
    ARGS_CHECK(argc,2);
    int fd = open(argv[1],O_RDWR);
    ERROR_CHECK(fd,-1,"open");
    
    char str[] = "1000000";
    write(fd,str,strlen(str));
    close(fd);
    return 0;
}
