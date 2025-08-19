#include <iostream>
using std::cout;
using std::endl;

namespace wd {
int num;

void print(){
    cout << "print()" << endl;
}

}

namespace wd {
int num2 = 300;

}
using namespace wd;


void test0(){
    print();
    num = 500;
    cout << num << endl;
    cout << num2 << endl;
 
}

int main(void)
{
    test0();
    return 0;
}

