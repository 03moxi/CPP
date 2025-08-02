#include <func.h>
#include <ctype.h>
int main(int argc, char *argv[])
{
    // ./3_homework_transfer file3
    ARGS_CHECK(argc,2);
    int fd = open(argv[1],O_RDWR);
    ftruncate(fd,498);
    char * p = (char *)mmap(NULL,498,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    for(int i = 0; i < 498; ++i){
        if(p[i] >= 'a' && p[i] <= 'z'){
            p[i] -= 32;
        }
        else if(ispunct(p[i])){
            p[i] = ' ';
        }
    }
    munmap(p,498);
    close(fd);
    return 0;
}

