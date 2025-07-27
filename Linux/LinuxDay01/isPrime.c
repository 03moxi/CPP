
#include<stdio.h>
#include<stdbool.h>

bool isPrime(long long n){
    if(n<=3)
        return n>=2;
    else if((n%2!=0)&&(n%3!=0)&&(n%4!=0)){
        return true;
    }          
    else
        return false;
}
int main(){
    long long n;
    scanf("%lld",&n);
    long long x=isPrime(n);
    if(x)
        printf("%lld 是素数\n",n);
    else
        printf("%lld 不是素数\n",n);


}
