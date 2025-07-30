#include <func.h>
int main(int argc, char *argv[])
{
    // ./1_fopen file1
   // if(argc != 2){
   //     fprintf(stderr,"args error!\n");
   //     return -1;
   // }
    ARGS_CHECK(argc,2);
    FILE *fp = fopen(argv[1],"r+");
//#ifdef DEBUG
//    if(fp == NULL){
//        perror("fopen");
//        return -1;
//    }
//#endif
    ERROR_CHECK(fp,NULL,"fopen"); 
    return 0;
}


