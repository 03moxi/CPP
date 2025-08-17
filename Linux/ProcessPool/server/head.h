#include <func.h>

enum {
    FALS,
    BUSY
};
// 0 1

typedef struct workerdata_s {
    pid_t pid;
    int status;
    int pipesockfd; // 父进程和子进程通信用的socketpair的fd
} workerdata_t;

int makeWorker(int workerNum,workerdata_t* workerArr);
int tcpInit(const char* ip,const char* port,int* psockfd);
int epollAdd(int epfd, int fd);
int epollDel(int epfd, int fd);
int sendfd(int sockfd, int fdthosend, int exitFlag);
int recvfd(int sockfd, int *pfdtorecv, int* pexitFlag);
int workLoop(int sockfd);
int transFile(int netfd);


