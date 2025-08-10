#include <func.h>

typedef struct node_s {
    int data;
    struct node_s* pNext;
} node_t;
typedef struct queue_s {
    node_t *pFront;
    node_t *pRear;
    int queueSize;
} queue_t;

int enQueue(queue_t *pQueue,int data){
    node_t *pNew = (node_t *)calloc(1,sizeof(node_t));
    pNew->data = data;

    if(pQueue->queueSize == 0){
        pQueue->pFront = pNew;
        pQueue->pRear = pNew;
    }
    else{
        pQueue->pRear->pNext = pNew;
        pQueue->pRear = pNew;
    }
    ++pQueue->queueSize;
    return 0; 
}
int deQueue(queue_t *pQueue){
    node_t *pCur = pQueue->pFront;
    pQueue->pFront = pQueue->pFront->pNext;
    if(pQueue->queueSize == 1){
        pQueue->pRear = NULL;
    }
    free(pCur);
    --pQueue->queueSize;
    return 0;
}
int visitQueue(queue_t *pQueue){
    node_t *pCur = pQueue->pFront;
    while(pCur){
        printf("%d ",pCur->data);
        pCur = pCur->pNext;
    }
    printf("\n");
    return 0;
}
//int main(int argc,char*argv[])
//{
//    queue_t myQueue;
//    memset(&myQueue,0,sizeof(myQueue));
//    for(int i=0;i<10;i++){
//        int data = rand()%100;
//        enQueue(&myQueue,data);
//        printf("data = %d\n",data);
//        visitQueue(&myQueue);
//    }
//    printf("-----------------------\n");
//    for(int i=0;i<10;i++){
//        int front = myQueue.pFront->data;
//        deQueue(&myQueue);
//        printf("front = %d\n",front);
//        visitQueue(&myQueue);
//    }
//    return 0;
//}
typedef struct shareRes_s {
    queue_t queue;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
} shareRes_t;

void *producer(void *arg){
    shareRes_t *pshareRes = (shareRes_t *)arg;
    
    while(1){
        pthread_mutex_lock(&pshareRes->mutex);
        while(pshareRes->queue.queueSize >= 10){
            pthread_cond_wait(&pshareRes->cond,&pshareRes->mutex);    
        }
        printf("before producer, current queuesize = %d\n", pshareRes->queue.queueSize);
        //printf("tid = %lu\n", pthread_self());
        int data = rand()%100;
        enQueue(&pshareRes->queue,data);
        printf("data = %d\n", data);
        visitQueue(&pshareRes->queue);
        printf("after producer, current queuesize = %d\n", pshareRes->queue.queueSize);
        pthread_cond_signal(&pshareRes->cond);
        pthread_mutex_unlock(&pshareRes->mutex);
        sleep(3);
    }
    //pthread_exit(NULL);
}
void *comsumer(void *arg){
    shareRes_t *pshareRes = (shareRes_t *)arg;
    
    sleep(5);
    while(1){
        pthread_mutex_lock(&pshareRes->mutex);
        while(pshareRes->queue.queueSize <= 0){
            pthread_cond_wait(&pshareRes->cond,&pshareRes->mutex);    
        }
        printf("before comsumer, current queuesize = %d\n", pshareRes->queue.queueSize);
        //printf("tid = %lu\n", pthread_self());
        int front = pshareRes->queue.pFront->data;
        deQueue(&pshareRes->queue);
        visitQueue(&pshareRes->queue);
        printf("front = %d\n", front);
        printf("after producer, current queuesize = %d\n", pshareRes->queue.queueSize);
        pthread_cond_signal(&pshareRes->cond);
        pthread_mutex_unlock(&pshareRes->mutex);
        sleep(1);
    }
    //pthread_exit(NULL);
}
int main(void)
{
    shareRes_t shareRes;
    memset(&shareRes,0,sizeof(shareRes.queue));
    pthread_mutex_init(&shareRes.mutex,NULL);
    pthread_cond_init(&shareRes.cond,NULL);
    
    // 插入8个元素
    for(int i = 0; i < 8; ++i){
        int data = rand()%100;
        enQueue(&shareRes.queue,data);
        printf("data = %d\n", data);
        visitQueue(&shareRes.queue);
    }
    printf("--------------------------\n");

    pthread_t tid1,tid2,tid3,tid4,tid5;
    pthread_create(&tid1,NULL,producer,&shareRes);
    pthread_create(&tid2,NULL,producer,&shareRes);
    pthread_create(&tid3,NULL,producer,&shareRes);
    pthread_create(&tid4,NULL,comsumer,&shareRes);
    pthread_create(&tid5,NULL,comsumer,&shareRes);

    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    pthread_join(tid3,NULL);
    pthread_join(tid4,NULL);
    pthread_join(tid5,NULL);
    return 0;
}
