#include <stdio.h>

int main(int argc,char*argv[])
{
    int n;
    scanf("%d",&n);
    while(n%2 == 0){
       n/=2;
    }
    while(n%3 == 0){
        n/=3;
    }
    while(n%5 == 0){
        n/=5;
    }
    if(n==0){
        printf("丑数\n");
    }else{
        printf("不是\n");
    }
    return 0;
}

