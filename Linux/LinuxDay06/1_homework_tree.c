#include <func.h>
int DFSprint(char *dirpath, int width){
    DIR *dirp = opendir(dirpath);
    ERROR_CHECK(dirp,NULL,"opendir");
    struct dirent * pdirent;
    while((pdirent = readdir(dirp)) != NULL){
        if(strcmp(pdirent->d_name,".") == 0 ||
           strcmp(pdirent->d_name,"..") == 0){
            continue;
        }

        printf("└");
        for(int i = 1; i < width; ++i){
            printf("─");
        }
        printf("%s\n", pdirent->d_name);
        if(pdirent->d_type == DT_DIR){
            char path[1024] = {0};
            sprintf(path,"%s%s%s",dirpath,"/",pdirent->d_name);
            DFSprint(path,width+6);
        }
    }
    closedir(dirp);
    return 0;
}
int main(int argc, char *argv[])
{
    // ./1_homework_tree dir1
    ARGS_CHECK(argc,2);
    printf("%s\n", argv[1]);
    DFSprint(argv[1],6);
    return 0;
}


