#include <iostream>
using std::cout;
using std::endl;

void test0(){
    int num = 100;
    int & ref = num;//声明ref时进行了初始化（绑定）
    //int & ref2; //error
    cout << num << endl;
    cout << ref << endl;
    cout << &num << endl;
    cout << &ref << endl;

    int num2 = 200;
    ref = num2; //这不是更改绑定，而是赋值操作
    //对引用操作就是对变量本身操作
    cout << ref << endl;//ref被改成了200
    cout << num << endl; //num也被改成了200
    cout << num2 << endl;
    cout << &num << endl;
    cout << &ref << endl;
    cout << &num2 << endl;

    num = 1000;
    cout << ref << endl;
}

int main(void)
{
    test0();
    return 0;
}

