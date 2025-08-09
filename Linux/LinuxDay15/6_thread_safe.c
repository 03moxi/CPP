#include <func.h>

void *threadFunc(void *arg){
    time_t now = time(NULL);
    char *p;
    char buf[1024] = {0};
    //p = ctime(&now);
    p = ctime_r(&now,buf);
    printf("Before p = %s\n", p);
    sleep(5);
    printf("After p = %s\n", p);
    pthread_exit(NULL);
}
int main(int argc,char*argv[])
{
    pthread_t tid;
    pthread_create(&tid,NULL,threadFunc,NULL);
    sleep(2);
    time_t now = time(NULL);
    char *p;
    char buf[10124] = {0};
    //p = ctime(&now);
    p = ctime_r(&now,buf);
    printf("Main p = %s\n", p);
    pthread_join(tid,NULL);
    return 0;
}

