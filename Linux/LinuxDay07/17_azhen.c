#include <func.h>
int main(int argc, char *argv[])
{
    // ./17_aqiang 1.pipe 2.pipe
    ARGS_CHECK(argc,3);
    int fdr = open(argv[1],O_RDONLY);
    int fdw = open(argv[2],O_WRONLY);
    printf("aqiang is connected!\n");
    return 0;
}
