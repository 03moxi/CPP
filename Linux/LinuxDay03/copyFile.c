#include <stdio.h>
#include <stdlib.h>

int main(int argc,char*argv[])
{
    if(argc != 3){
        fprintf(stderr, "Useage: ./copyFile src dst\n");
        exit(1);
    }
    FILE* src_fp=fopen(argv[1],"rb");
    if (src_fp == NULL) {
        fprintf(stderr, "open %s failed\n", argv[1]);
        exit(1);
    }
    char arr[1024];
    FILE* dst_fp=fopen(argv[2],"wb");
    if (dst_fp == NULL) {
        fprintf(stderr, "open %s failed\n", argv[2]);
        fclose(src_fp);
        exit(1);
    }
    int n;
    while((n = fread(arr,1,1024,src_fp))>0){
        fwrite(arr,1,n,dst_fp);
    }

    fclose(src_fp);
    fclose(dst_fp);
    return 0;
}

