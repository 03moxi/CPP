#include <func.h>
//普通锁
int main(int argc,char*argv[])
{
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    int ret;
    ret = pthread_mutex_trylock(&mutex);
    THREAD_ERROR_CHECK(ret,"first");
    printf("first lock!\n");
    ret = pthread_mutex_trylock(&mutex);
    THREAD_ERROR_CHECK(ret,"second");
    printf("second lock!\n");
    return 0;
}

