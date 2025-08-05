#include <func.h>

int main(int argc,char*argv[])
{
    printf("-");
    fork();
    sleep(1.5);
    printf("-");
    fork();
    return 0;
}

