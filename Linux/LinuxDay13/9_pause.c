#include <func.h>

void handler(int signum){
    printf("signum = %d\n",signum);
}

int main(int argc,char*argv[])
{
    signal(SIGALRM,handler);
    alarm(5);
    pause();
    printf("byebye\n");

    return 0;
}

