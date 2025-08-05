#include <func.h>

int main(int argc,char*argv[])
{
    if(fork()){
        exit(0);
    }
    else{
        printf("Before ,sid = %d\n",getsid(0));
        setsid();
        printf("After,sid = %d\n",getsid(0));
    }
    return 0;
}

