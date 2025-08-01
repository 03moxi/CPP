#include <func.h>
int main()
{
    // ./0_read_stdin
    char buf[1024] = {0};
    ssize_t sret = read(0,buf,sizeof(buf));
    ERROR_CHECK(sret,-1,"read");
    printf("sret = %ld, buf = %s\n", sret, buf);
    return 0;
}
