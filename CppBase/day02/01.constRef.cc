#include <iostream>
using std::cout;
using std::endl;

void func(const int &x,int &y){
    //x = 100;//error x是常变量
    y = 200;
}

void test0(){
    int a = 1, b = 2;
    func(a,b);
}

int main(void)
{
    test0();
    return 0;
}

