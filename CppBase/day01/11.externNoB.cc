#include <iostream>
using std::cout;
using std::endl;

namespace {

extern int num2;

}


void test0(){
    cout << num2 << endl;
}

int main(void)
{
    test0();
    return 0;
}

