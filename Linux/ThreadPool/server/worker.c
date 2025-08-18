#include "worker.h"
#include "taskQueue.h"
#include "threadPool.h"

int tidArrInit(tidArr_t * ptidArr, int workerNum){
    // 申请内存 存储每个子线程的tid
    ptidArr->arr = (pthread_t *)calloc(workerNum,sizeof(pthread_t));
    ptidArr->workerNum = workerNum;
    return 0;
}

void* threadFunc(void *arg){
    threadPool_t* pthreadPool = (threadPool_t *)arg;
    while(1){
        pthread_mutex_lock(&pthreadPool->mutex);
        while(pthreadPool->taskQueue.queueSize <= 0){
            pthread_cond_wait(&pthreadPool->cond,&pthreadPool->mutex);
        }
        int netfd = pthreadPool->taskQueue.pFront->netfd;
        printf("I am worker, I got a netfd = %d\n", netfd);
        deQueue(&pthreadPool->taskQueue);
        pthread_mutex_unlock(&pthreadPool->mutex);
        // 执行业务
        transFile(netfd);
        close(netfd);
    }
}
