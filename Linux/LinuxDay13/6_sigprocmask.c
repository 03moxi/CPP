#include <func.h>

void handler(int signum){
    printf("signum = %d\n",signum);
}

int main(int argc,char*argv[])
{
    signal(SIGINT,handler);

    sigset_t set;
    sigemptyset(&set);
    //清空信号集
    sigaddset(&set,SIGINT);
    sigset_t oldset;
    sigprocmask(SIG_BLOCK,&set,&oldset);

    sleep(10);

    sigset_t pending;
    sigpending(&pending);
    if(sigismember(&pending,SIGINT)){
        printf("SIGINT is pending!\n");
    }
    else{
        printf("SIGINT isnoy pending!\n");
    }
    sigprocmask(SIG_UNBLOCK,&set,NULL);
    sleep(1);
    return 0;
}

