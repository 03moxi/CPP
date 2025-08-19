#include <iostream>
using std::cout;
using std::endl;

namespace wd {
int num = 100;

void func(){
    cout << "func" << endl;
}
} // endl wd


void test0(){
    using namespace wd;
    cout << num << endl;
    func();
}

int main(void)
{
    test0();
    return 0;
}

