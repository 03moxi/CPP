#include <string.h>
#include <string>
#include <iostream>
#include <fstream>
using std::cout;
using std::endl;
using std::ifstream;
using std::string;

void test0(){
    ifstream ifs;
    //文件输入流对象是从文件中读取内容
    //需要绑定到一个存在的文件
    /* ifs.open("try.txt"); */
    ifs.open("05.explicit.cc");

    if(!ifs.good()){
        cout << "ifstream open file fail!" << endl;
        return;
    }
    
#if 0
    //方式一：兼容C的写法
    char buf[100] = {0};
    while(ifs.getline(buf,sizeof(buf))){
        cout << buf << endl;
        memset(buf,0,sizeof(buf));
    }
#endif

    //方式二：使用C++的string的getline函数
    string line;
    while(std::getline(ifs,line)){
        cout << line << endl;
    }

    //规范操作，使用完之后关闭流
    ifs.close();
}

int main(void)
{
    test0();
    return 0;
}

