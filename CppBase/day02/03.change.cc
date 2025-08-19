#include <iostream>
using std::cout;
using std::endl;

void test0(){
    int iNumber = 100;
    float fNumber = 0;
    fNumber = (float)iNumber;//C风格
    fNumber = static_cast<float>(iNumber);

    const char *pstr = "hello";
    //int *p = static_cast<int*>(pstr);//非法的转换，error
}

void test1(){
    const int number = 100;
    //int *pInt = &number;//error
    const int *pInt = &number;//OK
    int *pInt2 = const_cast<int *>(&number);
    *pInt2 = 1000;//这里修改的数据没有写回内存，在寄存器
    cout << *pInt2 << endl;
    cout << number << endl;
    cout << pInt2 << endl;
    cout << &number << endl;
}

int main(void)
{
    test1();
    return 0;
}

