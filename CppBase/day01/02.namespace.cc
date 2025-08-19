#include <iostream>
using std::cout;
using std::endl;


namespace wd {
int num = 100;

void func(){
    cout << "func" << endl;
}
} //endl wd

namespace hw {
int num = 100;

void func(){
    cout << "func" << endl;
}
} //endl hw


void test0(){
    cout << hw::num << endl;
    hw::func();
}

int main(void)
{
    test0();
    return 0;
}

