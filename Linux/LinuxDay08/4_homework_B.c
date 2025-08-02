#include <func.h>
int main(int argc, char *argv[])
{
    // ./4_homework_B 1.pipe
    ARGS_CHECK(argc,2);
    int fdr = open(argv[1],O_RDONLY);
    char buf[1024] = {0};
    read(fdr,buf,sizeof(buf));
    printf("buf = %s\n", buf);
    return 0;
}
