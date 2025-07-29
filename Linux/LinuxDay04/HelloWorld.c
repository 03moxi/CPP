#include <stdio.h>
#define DEBUG 
int main(int argc,char*argv[])
{
#if defined DEBUG
    printf("Hello World!\n");
    return 0;
#endif
    printf("调试代码!\n");
    return 0;
}

