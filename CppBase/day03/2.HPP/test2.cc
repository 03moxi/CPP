#include "test.hpp"
using std::cout;
using std::endl;

extern void test1();

void test0(){
    print();
}

int main(void)
{
    test0();
    test1();
    return 0;
}

