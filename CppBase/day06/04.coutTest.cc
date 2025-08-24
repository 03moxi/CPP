#include <unistd.h>
#include <iostream>
using std::cout;
using std::endl;
using std::cerr;

void test0(){
    for(int i=0;i<5;++i){
        cout << 'a' << endl;
    }
    sleep(2);
}

void test1(){
    //没有马上刷新
    for(int i = 0; i < 1024; ++i){
        cout << 'a'; 
    }
    sleep(2);
    cout << 'b';
    sleep(2);
}

void test2(){
    for(int i = 0; i < 5; ++i){
        //cerr不带缓冲
        cerr << 'a';
    }
    sleep(2);
}
int main(void)
{
    test2();
    return 0;
}

