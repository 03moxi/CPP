#include <func.h>

void handler(int signum){
    printf("before signum = %d\n",signum);
    sleep(5);
    printf("after signum = %d\n",signum);
}

int main(int argc,char*argv[])
{
    struct sigaction act;
    memset(&act,0,sizeof(act));
    act.sa_handler = handler;

    //SA_RESTART 自动重启低速
    //SA_NODEFER 不临时屏蔽本信号
    //SA_NODEFER 注册一次，生效一次
    //act.sa_flags = SA_RESTART | SA_NODEFER;
    //act.sa_flags = SA_RESTART|SA_RESETHAND;
    act.sa_flags = SA_RESTART;
    
    //清空
    sigemptyset(&act.sa_mask);
    //临时屏蔽
    sigaddset(&act.sa_mask,SIGQUIT);
    sigaction(SIGINT,&act,NULL);
    sigaction(SIGQUIT,&act,NULL);

    char buf[4096] = {0};
    ssize_t sret = read(STDIN_FILENO,buf,sizeof(buf));
    printf("sret = %ld,buf = %s\n",sret,buf);

    return 0;
}

