#include <string>
#include <sstream>
#include <iostream>
using namespace std;

void test0(){
    int num = 123, num2 = 456;
    ostringstream oss;
    //把所有的内容都传给了字符串输出流对象
    oss << "num = " << num << " , num2 = " << num2;
    /* cout << oss.str() << endl; */
    string line = oss.str();
    cout << line << endl;
}

int main(void)
{
    test0();
    return 0;
}

