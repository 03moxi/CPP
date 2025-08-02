#include <func.h>
int main(int argc, char *argv[])
{
    // ./0_azhen 1.pipe 2.pipe
    ARGS_CHECK(argc,3);
    int fdw = open(argv[1],O_WRONLY);
    ERROR_CHECK(fdw,-1,"open write");
    int fdr = open(argv[2],O_RDONLY);
    ERROR_CHECK(fdr,-1,"open read");
    printf("azhen is connected!\n");
    char buf[4096];
    fd_set rdset; // 为fd_set申请内存
    time_t curTime;
    time_t lastActive = time(NULL);
    while(1){
        // select之前需要重置监听集合
        FD_ZERO(&rdset); // fd_set 开始是监听集合
        FD_SET(STDIN_FILENO,&rdset);
        FD_SET(fdr,&rdset); //把fdr 和 stdin 加入监听
        struct timeval timeout;
        timeout.tv_sec = 1;
        timeout.tv_usec = 0;
        int ret = select(fdr+1,&rdset,NULL,NULL,&timeout);
        curTime = time(NULL); // 更新当前时间
        printf("curTime = %s\n", ctime(&curTime));
        // select返回，说明fdr or stdin就绪了 rdset现在是就绪集合
        if(FD_ISSET(fdr,&rdset)){
            // 管道就绪 读取阿强的消息
            // 更新阿强的lastActive
            lastActive = time(NULL);
            memset(buf,0,sizeof(buf));
            ssize_t sret =read(fdr,buf,sizeof(buf));
            if(sret == 0){
                printf("Hehe\n");
                break;
            }
            printf("buf = %s\n", buf);
        }
        if(FD_ISSET(STDIN_FILENO,&rdset)){
            // 读取stdin的数据
            memset(buf,0,sizeof(buf));
            ssize_t sret = read(STDIN_FILENO,buf,sizeof(buf));
            if(sret == 0){
                write(fdw,"nishigehaoren",13);
                break;
            }
            write(fdw,buf,strlen(buf));
        }
        if(curTime - lastActive >= 10){
            printf("byebye!\n");
            break;
        }
    }
    close(fdr);
    close(fdw);
    return 0;
}

