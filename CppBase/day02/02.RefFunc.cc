#include <iostream>
using std::cout;
using std::endl;

int gNumber  = 100;

int func(){
    cout << "gNumber:" << gNumber << endl;
    return gNumber;
}

int &func2(){
    cout << "gNumber:" << gNumber << endl;
    int &ref = gNumber;
    return ref;
}

//int &func3(){
//    int lNumber = 1;
//    return lNumber;
//}

int &func4(){
    int *hNumber = new int(1);
    cout << *hNumber << endl;
    return *hNumber;
}

void test0(){
    //cout << &func() << endl;//返回的是临时变量，不能取地址
    cout << &func2() << endl;
    cout << &gNumber << endl;
    //cout << func3() << endl;//error
    //cout << func4() << endl;
    //cout << &func4() << endl;
    int &ref = func4();
    ref = 100;
    delete &ref;
}

int main(void)
{
    test0();
    return 0;
}

