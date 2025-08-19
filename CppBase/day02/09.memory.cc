#include <iostream>
using std::cout;
using std::endl;

int globalNumber = 8;

void test0(){
    int localNumber = 1;
    int * p = new int(20);
    static int sNumber = 9;
    //编译器优化效果，使得栈区的生长方向看起来和堆区一样
    cout << "&p:" << &p << endl;
    cout << "&localNumber:" << &localNumber << endl;
    cout << "&heapNumber:" << p << endl;
    cout << "&sNumber:" << &sNumber << endl;
    cout << "&globalNumber:" << &globalNumber << endl;


    const char * pstr = "hello";
    void * p2 = (void*)pstr;
    cout << p2 << endl;
    printf("%p\n",pstr);


     printf("%p\n",&test0);
}

int main(void)
{
    test0();
    return 0;
}

