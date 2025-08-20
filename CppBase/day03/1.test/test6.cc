#include <iostream>

using std::cout;
using std::endl;

void test0()
{
    int a[5] = {1,2,3,4,5};
    cout << a + 1 << endl;
    cout << &a + 1 << endl;
    int *ptr=(int *)(&a+1);
    printf("%d,%d",*(a+1),*(ptr-1));
}

int main()
{
    test0();
    return 0;
}

