#include <func.h>

int func(){
    //return 0;
    exit(123);
    // _exit(234);
}

int main(int argc,char*argv[])
{
    printf("Hello");
    func();
    printf("Can you see me?\n");
    return 0;
}

