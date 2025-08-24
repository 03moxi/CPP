#include <iostream>
#include <sstream>
#include <string>
using std::cout;
using std::endl;
using std::string;
using std::istringstream;

void test0(){
    string s("123 456");
    int num = 0;
    int num2 = 0;
    //将字符串内容传递给了字符串输入流对象  
    istringstream iss(s);
    //默认以空格、换行符、制表符为间隔符
    iss >> num >> num2;
    cout << "num:" << num << endl;
    cout << "num2:" << num2 << endl;
}

int main(void)
{
    test0();
    return 0;
}

