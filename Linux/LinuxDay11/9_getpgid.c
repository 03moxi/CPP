#include <func.h>

int main(int argc,char*argv[])
{
    if(fork()){
        printf("I am parent, pid = %d, pgid = %d, pgid of ppid = %d\n",
               getpid(),getpgid(0),getpgid(getppid()));
        wait(NULL);
    }
    else{
        printf("Before I am child, pid = %d, pgid = %d, pgid of ppid = %d\n",
               getpid(),getpgid(0),getpgid(getppid()));
               setpgid(0,0); //父进程不能改组因为它是组长
               printf("After I am child, pid = %d, pgid = %d, pgid of ppid = %d\n",
                      getpid(),getpgid(0),getpgid(getppid()));
               while(1){
               sleep(1);
               }
    }
    return 0;
}

