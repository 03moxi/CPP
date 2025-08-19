#include <iostream>
using std::cout;
using std::endl;

int add(int x,int y = 1){
    return x + y;
}

int add(int x){
    return x;
}

void test0(){
    cout << add(24,30) << endl;
    //缺省调用
    //cout << add(100) << endl;//error 编译器不知道调用那个add
    //cout << add() << endl;
}

int multiply(int x = 100,int y = 50);

int multiply(int x,int y){
    return x * y;
}

void test1(){
    cout << multiply() << endl;
}

int main(void)
{
    test1();
    return 0;
}

