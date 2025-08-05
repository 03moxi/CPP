#include <func.h>

int main(int argc,char*argv[])
{
    //创建共享内存段
    int shmid = shmget(0x1234,4096,IPC_CREAT|0600);
    ERROR_CHECK(shmid,-1,"shmget");
    printf("shmid = %d\n",shmid);
    //连接进程地址空间(就是连接虚拟内存)
    int *p = (int *)shmat(shmid,NULL,0);
    printf("*p = %d\n",*p);
    return 0;
}

