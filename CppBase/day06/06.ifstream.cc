#include <string>
#include <iostream>
#include <fstream>
using std::cout;
using std::endl;
using std::string;
using std::ifstream;

void test0(){
    ifstream ifs;
    //文件输入流对象是从文件中读取内容
    //需要绑定到一个存在的文件
    //ifs.open("try.txt");
    ifs.open("05.explicit.cc");

    if(!ifs.good()){
        cout << "ifstream open file fail!" << endl;
        return;
    }
    
    //默认以换行符、空格作为间隔符
    //一次读取一个字符串
    string word;
    cout << word.size() << endl;
    cout << word.capacity() << endl;
    //只要ifs是goodbot状态就会一直读取
    while(ifs >> word){
        cout << word.size() << endl;
        cout << word.capacity() << endl;
        cout << word << endl;
    }

    cout << word.size() << endl;

    //规范操作，使用完之后关闭流
    ifs.close();

}

int main(void)
{
    test0();
    return 0;
}

