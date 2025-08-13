#include <func.h>
int main(int argc, char *argv[])
{
    int fd = open("1.pipe",O_WRONLY);
    write(fd,"howareyou",9);

    sleep(20);
    printf("sleep over!\n");
    close(fd);
    return 0;
}


