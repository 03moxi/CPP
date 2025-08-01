#include <func.h>
int main(int argc, char *argv[])
{
    // ./17_azhen 2.pipe 1.pipe
    ARGS_CHECK(argc,3);
    int fdr = open(argv[1],O_RDONLY);
    int fdw = open(argv[2],O_WRONLY);
    printf("azhen is connected!\n");
    return 0;
}
