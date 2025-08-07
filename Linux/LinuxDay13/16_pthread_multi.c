#include <func.h>

void *threadFunc(void *arg){
    int *pi = (int *)arg;
    printf("*pi = %d\n",*pi);
    return NULL;
}

int main(int argc,char*argv[])
{
    int i = 1001;
    pthread_t tid1,tid2,tid3;
    pthread_create(&tid1,NULL,threadFunc,&i);
    ++i;
    pthread_create(&tid2,NULL,threadFunc,&i);
    ++i;
    pthread_create(&tid3,NULL,threadFunc,&i);
    sleep(1);
    return 0;
}

