#include <func.h>

void *threadFunc(void *arg){
    int *p = (int *)arg;
    sleep(1);
    printf("*p = %d\n",*p);
    return NULL;
}

int main(int argc,char*argv[])
{
    int *p = (int *)malloc(sizeof(int));
    *p = 1000;
    pthread_t tid;
    pthread_create(&tid,NULL,threadFunc,p);
    free(p);
    sleep(2);
    return 0;
}

