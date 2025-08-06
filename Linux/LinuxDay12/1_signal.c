#include <func.h>

void handler(int signum){
    printf("signum = %d\n",signum);
}

int main(int argc,char*argv[])
{
    sleep(5);
    printf("sleep over\n");
    signal(SIGINT,handler);
    while(1){
        sleep(1);
    }
    return 0;
}

