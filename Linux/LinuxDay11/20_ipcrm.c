#include <func.h>

int main(int argc,char*argv[])
{
    int shmid = shmget(0x1234,4096,IPC_CREAT|0600);
    ERROR_CHECK(shmid,-1,"shmget");
    shmat(shmid,NULL,0);
    while(1){
        sleep(1);
    }
    return 0;
}

