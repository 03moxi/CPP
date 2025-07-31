#include <func.h>
#include <pwd.h>
#include <grp.h>
int setTypeMode(mode_t mode, char *str){
    switch (mode & S_IFMT) {
    case S_IFBLK:  str[0] = 'b';break;
    case S_IFCHR:  str[0] = 'c';break;
    case S_IFDIR:  str[0] = 'd';break;
    case S_IFIFO:  str[0] = 'p';break;
    case S_IFLNK:  str[0] = 'l';break;
    case S_IFREG:  str[0] = '-';break;
    case S_IFSOCK: str[0] = 's';break;
    default:       str[0] = '?';break;
    }
    int i = 1 << 8; // 100000000
    if(mode & i){
        str[1] = 'r';
    }
    else{
        str[1] = '-';
    }
    i >>= 1;
    if(mode &i){
        str[2] = 'w';
    }
    else{
        str[2] = '-';
    }
    i >>= 1;
    if(mode &i){
        str[3] = 'x';
    }
    else{
        str[3] = '-';
    }
    i >>= 1;
    if(mode & i){
        str[4] = 'r';
    }
    else{
        str[4] = '-';
    }
    i >>= 1;
    if(mode &i){
        str[5] = 'w';
    }
    else{
        str[5] = '-';
    }
    i >>= 1;
    if(mode &i){
        str[6] = 'x';
    }
    else{
        str[6] = '-';
    }
    i >>= 1;
    if(mode & i){
        str[7] = 'r';
    }
    else{
        str[7] = '-';
    }
    i >>= 1;
    if(mode &i){
        str[8] = 'w';
    }
    else{
        str[8] = '-';
    }
    i >>= 1;
    if(mode &i){
        str[9] = 'x';
    }
    else{
        str[9] = '-';
    }
    str[10] = '\0';
    return 0;
}
int getTimeStr(time_t mtime, char *str){
    char monArr[][10] = {
        "Jan", "Feb", "Mar", "Apr", "May", "Jun",
        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };
    struct tm* tmVal = localtime(&mtime);
    int mon = tmVal->tm_mon;
    int mday = tmVal->tm_mday;
    int hour = tmVal->tm_hour;
    int min = tmVal->tm_min;
    sprintf(str,"%s %02d %02d:%02d",monArr[mon],
                                   mday,
                                   hour,
                                   min);
    return 0;
}
int main(int argc, char *argv[])
{
    // ./0_homework_ls_al dir1 
    ARGS_CHECK(argc,2);
    DIR *dirp = opendir(argv[1]);
    ERROR_CHECK(dirp,NULL,"opendir");
    struct dirent * pdirent;
    chdir(argv[1]);
    while((pdirent = readdir(dirp))!= NULL){
        struct stat statbuf;
        int ret = stat(pdirent->d_name,&statbuf);
        ERROR_CHECK(ret,-1,"stat");
        char str[20] = {0}; // str 保存类型和权限
        setTypeMode(statbuf.st_mode,str);        
        char timeStr[20] = {0};
        getTimeStr(statbuf.st_mtime,timeStr);
        printf("%s %ld %s %s %4ld %s %s\n", str,
                              statbuf.st_nlink,
                              getpwuid(statbuf.st_uid)->pw_name,
                              getgrgid(statbuf.st_gid)->gr_name,
                              statbuf.st_size,
                              timeStr,
                              pdirent->d_name);
    }
    closedir(dirp);
    return 0;
}


