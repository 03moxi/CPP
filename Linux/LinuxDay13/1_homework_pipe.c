#include <func.h>

int main(int argc,char*argv[])
{
    int fds[2];
    pipe(fds);
    if(fork()){
        close(fds[0]);
        sleep(5);
        printf("sleep over!\n");
        write(fds[1],"hello",5);
    }
    else{
        close(fds[1]);
        char buf[4096];
        ssize_t sret = read(fds[0],buf,4096);
        printf("sret = %ld, buf = %s\n",sret,buf);
    }
    
    
    return 0;
}

