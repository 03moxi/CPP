#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;

void test0(){
    string str;
    cout << "str:" << str << endl;
    //判空 空返回1 非空返回0
    cout << "is str empty:" << str.empty() << endl;
    cout << "str's size:" << str.size() << endl;

    cout << endl;
    string str1(5,'a');
    cout << "str1:" << str1 <<endl;
    cout << "is str1 empty:" << str1.empty() << endl;
    cout << "str1's size:" << str1.size() << endl;

    cout << endl;
    string str2("hello");
    cout << "str2:" << str2 << endl;
    cout << "is str2 empty:" << str2.empty() << endl;
    cout << "str2's size:" << str2.size() << endl;

    cout << endl;
    string str3("aaabbbbb",2);
    cout << "str3:" << str3 << endl;
    
    string str4(str3);
    string str5 = str3;
    cout << "str4:" << str4 << endl;
    cout << "str5:" << str5 << endl;

    //使用拼接方式创建字符串
    string str6 = str2 + ',' + str3;
    string str7 = str2 + ",world";
    cout << str6 << endl;
    cout << str7 << endl;

}

int main(void)
{
    test0();
    return 0;
}

