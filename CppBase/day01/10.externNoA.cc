#include <iostream>
using std::cout;
using std::endl;

static int num = 100;
static void print(){
    cout << "static print" << endl;
}

namespace
{
int num2 = 300;

void print(){
    cout << "Anonymous print" << endl;
}

}
