//编写代码，验证一下自己的机器是大端模式还是小端模式？
#include <func.h>

int main(int argc,char*argv[])
{
    int ret = 0x1234;
    char *p = (char *)&ret;
    printf("%x\n",*p);
    return 0;
}

