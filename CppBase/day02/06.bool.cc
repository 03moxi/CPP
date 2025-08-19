#include <iostream>
using std::cout;
using std::endl;

void test0(){
    bool b1 = 0;
    bool b2 = 100;
    bool b3 = 1;
    bool b4 = -1;

    cout << "b1:" << b1 << endl;
    cout << "b2:" << b2 << endl;
    cout << "b3:" << b3 << endl;
    cout << "b4:" << b4 << endl;

    //true
    if(b4){
        cout << "hello" << endl;
    }

    //false
    if(b1){
        cout << "hello" << endl;
    }

    cout << "sizeof(bool):" << sizeof(bool) << endl;
}

int main(void){
    test0();
    return 0;
}
