#include <func.h>

void *threadFunc(void *arg){
    //return NULL;
    //pthread_exit(NULL);
    int *p = (int *)malloc(sizeof(int));
    pthread_exit(p);
}

int main(int argc,char*argv[])
{
    pthread_t tid;
    pthread_create(&tid,NULL,threadFunc,NULL);

    void* retval;
    pthread_join(tid,&retval);
    printf("retval = %ld\n",(long)retval);
    return 0;
}

