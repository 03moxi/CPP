#include <func.h>
int main()
{
    // ./4_getcwd
    //  char path[128] = {0};
    //char path[1024] = {0};
    //char *path = (char *)malloc(1024);
    ////char *p = getcwd(path,sizeof(path));
    //char *p = getcwd(path,1024);
    //ERROR_CHECK(p,NULL,"getcwd");
    //printf("cwd = %s\n", path);
    
    char *p = getcwd(NULL,0);
    printf("p = %s\n", p);
    return 0;
}


