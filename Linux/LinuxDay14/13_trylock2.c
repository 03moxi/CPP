#include <func.h>
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
void *threadFunc(void *arg){
    pthread_mutex_lock(&mutex);
    pthread_exit(NULL);
}
int main(int argc, char *argv[])
{
    pthread_t tid;
    pthread_create(&tid,NULL,threadFunc,NULL);
    sleep(1);
    int ret = pthread_mutex_trylock(&mutex);
    THREAD_ERROR_CHECK(ret,"trylock");
    printf("I got lock!\n");
    pthread_mutex_unlock(&mutex);
    return 0;
}
