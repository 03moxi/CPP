#include <func.h>

enum {
    FALS,
    TRUE
};
// 0 1

typedef struct workerdata_s {
    pid_t pid;
    int status;
} workerdata_t;

int makeWorker(int workerNum,workerdata_t* workerArr);
