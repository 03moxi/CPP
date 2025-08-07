#include <func.h>

void handler(int signum){
    printf("signum = %d\n",signum);
    time_t now = time(NULL);
    printf("now = %s\n",ctime(&now));
}

int main(int argc,char*argv[])
{
    signal(SIGALRM,handler);
    alarm(10);
    handler(0);
    while(1){
        sleep(1);
    }
    return 0;
}

