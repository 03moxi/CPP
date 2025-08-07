#include <func.h>

void handler(int signum, siginfo_t *siginfo, void *p){
    printf("signum = %d, uid = %d\n",signum,siginfo->si_uid);
}

int main(int argc,char*argv[])
{
    struct sigaction act;
    memset(&act,0,sizeof(act));
    act.sa_sigaction = handler;
    act.sa_flags = SA_RESTART|SA_SIGINFO;
    sigaction(SIGINT,&act,NULL);
    sigaction(SIGQUIT,&act,NULL);

    char buf[4096] = {0};
    ssize_t sret = read(STDIN_FILENO,buf,sizeof(buf));
    printf("sret = %ld,buf = %s\n",sret,buf);
    return 0;
}

