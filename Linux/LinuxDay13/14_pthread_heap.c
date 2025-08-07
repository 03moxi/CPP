#include <func.h>

void *threadFunc(void *arg){
    int *p =(int *)arg;
    printf("child *p = %d\n",*p);
    ++*p;
    return NULL;
}

int main(int argc,char*argv[])
{
    int *p = (int *)malloc(sizeof(int));
    *p = 1000;
    pthread_t tid;
    pthread_create(&tid,NULL,threadFunc,p);
    sleep(1);
    printf("parent *p = %d\n",*p);
    return 0;
}

