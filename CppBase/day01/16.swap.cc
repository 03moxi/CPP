#include <iostream>
using std::cout;
using std::endl;

void swap(int x, int y){//值传递，发生复制
    int temp = x;
    x = y;
    y = temp;
}

void swap2(int * px, int * py){//地址传递，不复制
    int temp = *px;
    *px = *py;
    *py = temp;
}

//在实参传给swap3时，
//其实就是发生了初始化int & x = a;
//int & y = b;
void swap3(int & x, int & y){//引用传递，不复制
    int temp = x;
    x = y;
    y = temp;
}


void test0(){
    int a = 1, b = 2;
    swap2(&a,&b);
    cout << "a:" << a << endl;
    cout << "b:" << b << endl;
}

void test1(){
    int a = 1, b = 2;
    swap3(a,b);
    cout << "a:" << a << endl;
    cout << "b:" << b << endl;
}

int main(void)
{
    test0();
    test1();
    return 0;
}

