#include <iostream>
using std::cout;
using std::endl;

namespace wd {
int num = 100;

void func(){
    cout << "func" << endl;
}

namespace cpp {
int num = 200;

void func(){
    cout << "cpp::func" << endl;
}
} // endl cpp

}


void test0(){
    using namespace wd::cpp;
    cout << num << endl;
    func();
}

int main(void)
{
    test0();
    return 0;
}

