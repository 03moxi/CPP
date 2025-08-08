#include <func.h>

#define NUM 1000000

void *threadFunc(void *arg){
    
    int *p = (int *)arg;
    for(int i=0;i<NUM;i++){
        ++*p;
    }
    pthread_exit(NULL);
}

int main(int argc,char*argv[])
{
    int val = 0;
    pthread_t tid;
    pthread_create(&tid,NULL,threadFunc,&val);
    for(int i = 0; i < NUM; ++i){
        ++val;
    }
    pthread_join(tid,NULL);
    printf("val = %d\n", val);

    return 0;
}

