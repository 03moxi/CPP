#include <func.h>
int dataSeg = 1;
int main(int argc, char *argv[])
{
    int stack = 2;
    int *pHeap = (int *)malloc(sizeof(int));
    *pHeap = 3;
    if(fork()){
        // 父进程
        sleep(2);
        printf("I am parent, dataSeg = %d, stack = %d, heap = %d\n",
               dataSeg, stack, *pHeap);
    }
    else{
        // 子进程
        dataSeg += 3;
        stack += 3;
        *pHeap += 3;
        printf("I am child, dataSeg = %d, stack = %d, heap = %d\n",
               dataSeg, stack, *pHeap);
    }
    return 0;
}

