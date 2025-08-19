#include <iostream>
using std::cout;
using std::endl;

extern int num; //外部引入声明
extern void print();

namespace wd2 {

extern int num;

extern void print();

}
void test0(){
    using wd2::num;
    using wd2::print;
    cout << num << endl;
    print();

}
void test1(){
    cout << wd2::num << endl;
    wd2::print();
}

int main(void)
{
    test0();
    test1();
    return 0;
}

