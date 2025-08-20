#include <iostream>
using std::cout;
using std::endl;

void test0(){
    int num = 1;
    &num;//可以取地址的变量称为左值

    int &ref = num;
    const int &ref2 = num;

    //临时变量、匿名变量、临时对象、匿名对象
    //&1;//不能取地址的变量称为右值
    //int & ref3 = 1;//error
    const int &ref4 = 1;
}

int main(void)
{
    test0();
    return 0;
}

