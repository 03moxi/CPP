#include <func.h>

pthread_mutex_t mutex;

void *threadFunc(void *arg) {
    pthread_mutex_lock(&mutex);  // 子线程加锁
    printf("Thread got lock!\n");
    pthread_mutex_unlock(&mutex);  // 子线程释放锁
    pthread_exit(NULL);  // 子线程退出
}

int main(int argc, char *argv[]) {
    pthread_mutexattr_t mutexattr;
    pthread_mutexattr_init(&mutexattr);
    pthread_mutexattr_settype(&mutexattr, PTHREAD_MUTEX_ERRORCHECK);  // 错误检查锁

    pthread_mutex_init(&mutex, &mutexattr);  // 初始化互斥锁

    pthread_t tid;
    pthread_create(&tid, NULL, threadFunc, NULL);  // 创建子线程

    sleep(1);  // 等待子线程执行

    // 主线程尝试获取锁
    int ret = pthread_mutex_lock(&mutex);  
    if (ret == 0) {
        printf("I got lock!\n");
        pthread_mutex_unlock(&mutex);  // 解锁
    } else {
        printf("Failed to lock: %d\n", ret);
    }

    pthread_join(tid, NULL);  // 等待子线程退出

    return 0;
}

