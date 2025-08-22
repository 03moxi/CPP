#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;

void test0(){
    string str("hello");
    printf("%s\n",str.c_str());

    str.push_back('!');
    cout << str << endl;

    str.append(5,'!');
    cout << str << endl;

    str.append("world");
    cout << str << endl;

    string str2(",wangdao");
    str.append(str2);
    cout << str << endl;

   str.append(str2,0,5);
   cout << str << endl;
}

void test1(){
    string str("hello");
    //pos是从0开始的
    size_t pos = str.find('e');
    cout << pos << endl;

    string str2("lly");
    cout << str.find(str2) << endl;
}

int main(void)
{
    test1();
    return 0;
}

