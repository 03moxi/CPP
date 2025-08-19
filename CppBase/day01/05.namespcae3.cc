#include <iostream>
using std::cout;
using std::endl;

namespace wd {
int num = 100;

void func(){
    cout << "func" << endl;
}
} //endl wd

using wd::num;
using wd::func;

void test0(){
    cout << num << endl;
    func();
}

int main(void)
{
    test0();
    return 0;
}

