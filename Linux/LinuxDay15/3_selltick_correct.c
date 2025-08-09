#include <func.h>
typedef struct shareRes_s {
    int ticketNum;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
} shareRes_t;


void *sellWindow1(void *arg){
    shareRes_t *pshareRes = (shareRes_t *)arg;
    while(1){
        pthread_mutex_lock(&pshareRes->mutex);
        if(pshareRes->ticketNum <= 0){
            pthread_mutex_unlock(&pshareRes->mutex);
            break;
        }
        printf("before window1, ticketNum = %d\n", pshareRes->ticketNum);
        --pshareRes->ticketNum;
        printf("after window1, ticketNum = %d\n", pshareRes->ticketNum);
        pthread_mutex_unlock(&pshareRes->mutex);
    }
    pthread_exit(NULL);
}

void *sellWindow2(void *arg){
    shareRes_t *pshareRes = (shareRes_t *)arg;
    while(1){
        pthread_mutex_lock(&pshareRes->mutex);
        if(pshareRes->ticketNum <= 0){
            pthread_mutex_unlock(&pshareRes->mutex);
            break;
        }
        printf("before window1, ticketNum = %d\n", pshareRes->ticketNum);
        --pshareRes->ticketNum;
        printf("after window1, ticketNum = %d\n", pshareRes->ticketNum);
        pthread_mutex_unlock(&pshareRes->mutex);
    }
    pthread_exit(NULL);
}


int main(int argc,char*argv[])
{
    shareRes_t shareRes;
    shareRes.ticketNum = 20;
    pthread_mutex_init(&shareRes.mutex,NULL);
    pthread_cond_init(&shareRes.cond,NULL);

    pthread_t tid1,tid2;
    pthread_create(&tid1,NULL,sellWindow1,&shareRes);
    pthread_create(&tid2,NULL,sellWindow2,&shareRes);
    
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);

    return 0;
}

