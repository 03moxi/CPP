#include <func.h>

int main(int argc,char*argv[])
{
    if(fork()){
        printf("I am parent, pid = %d, pgid = %d, pgid of ppid = %d\n",
               getpid(),getpgid(0),getpgid(getppid()));
        wait(NULL);
    }
    else{
        printf("I am child, pid = %d, pgid = %d, pgid of ppid = %d\n",
               getpid(),getpgid(0),getpgid(getppid()));
    }
    return 0;
}

