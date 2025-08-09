#include <func.h>
int flag = 0;

void A(){
    printf("Before A\n");
    sleep(3);
    printf("After A\n");
}
void B(){
    printf("Before B\n");
    sleep(3);
    printf("After B\n");
}
void *threadFunc(void *arg){
    pthread_mutex_t *mutex = (pthread_mutex_t *)arg;
    while(1){
        pthread_mutex_lock(mutex);
        if(flag){
            B();
            pthread_exit(NULL);
        }
        pthread_mutex_unlock(mutex);
    }
    pthread_exit(NULL);
}
int main(int argc,char*argv[])
{
    pthread_mutex_t mutex;
    pthread_mutex_init(&mutex,NULL);

    pthread_t tid;
    pthread_create(&tid,NULL,threadFunc,&mutex);
    sleep(3);
    pthread_mutex_lock(&mutex);
    A();
    pthread_mutex_unlock(&mutex);
    flag = 1;
    pthread_join(tid,NULL);

    return 0;
}

