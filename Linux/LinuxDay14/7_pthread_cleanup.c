#include <func.h>

void freep1(void *arg){
    printf("free p1\n");
    free((int *)arg);
}
void freep2(void *arg){
    printf("free p2\n");
    free((int *)arg);
}
void closefd3(void *arg){
    int *pfd = (int *)arg;
    printf("close fd3\n");
    close(*pfd);
}

void *threadFunc(void *arg){
    int *p1 = (int *)malloc(4);
    pthread_cleanup_push(freep1,p1);
    int *p2 = (int *)malloc(4);
    pthread_cleanup_push(freep2,p2);
    int fd3 = open("file1",O_RDONLY);
    pthread_cleanup_push(closefd3,&fd3);
    printf("----------------------\n");
    pthread_exit(NULL);

    pthread_cleanup_pop(1);

    pthread_cleanup_pop(1);

    pthread_cleanup_pop(1);
}

int main(int argc,char*argv[])
{
    pthread_t tid;
    pthread_create(&tid,NULL,threadFunc,NULL);

    pthread_join(tid,NULL);
    
    return 0;
}

