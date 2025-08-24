#include <string.h>
#include <string>
#include <iostream>
#include <fstream>
using std::cout;
using std::endl;
using std::ofstream;
using std::string;

void test0(){
    /* ofstream ofs; */
    /* ofs.open("rec.txt"); */

    ofstream ofs("rec.txt",std::ios::app);

    string line("Hello World!");
    ofs << line;

    //将程序中的C风格字符串内容写入到文件
    /* char buff[100] = "wangdao cpp!\n"; */
    const char* buff = "wangdao cpp!\n";
    ofs.write(buff,strlen(buff));

    string str("summer\n");
    ofs.write(str.c_str(),str.size());

    ofs.close();
}

int main(void)
{
    test0();
    return 0;
}

