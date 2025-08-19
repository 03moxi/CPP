#include <iostream>
#include <string.h>
using std::cout;
using std::endl;

void test0(){
    char a[] = {'a','b','c','\0'};
    char b[] = "abcd";
    cout << a << endl;
    cout << b << endl;

    const char *p = "hello";
    cout << p << endl;

    char *p2 = new char[10]();
    strcpy(p2,p);
    cout << p2 << endl;

    const char *p3 = new char[4]{"abc"};

    //int *pint = new int[3]{1,2,3};
}

int main(void)
{
    test0();
    return 0;
}

