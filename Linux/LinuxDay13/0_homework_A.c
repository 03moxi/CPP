#include <func.h>

int main(int argc,char*argv[])
{
    if(fork()){
        wait(NULL);
        printf("child is finished!\n");
    }
    else{
        printf("I am child\n");
        system("./0_homework_B ./");
    }
    return 0;
}

