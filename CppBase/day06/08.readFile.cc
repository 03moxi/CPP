#include <string>
#include <iostream>
#include <fstream>
using std::cout;
using std::endl;
using std::ifstream;
using std::string;

void test0(){
    //ifstream ifs("05.explicit.cc");
    //游标默认在结尾
    ifstream ifs("05.explicit.cc",std::ios::ate);

    if(!ifs.good()){
        cout << "ifstream open file fail!" << endl;
        return;
    }

    //读取一个文件的全部内容
    //先获取一共有多少个字符
    cout << ifs.tellg() << endl;

    //ate模式创建ifs，则不需要进行这一步
    //ifs.seekg(0,std::ios::end);//将游标偏移到末尾，获取字符数
    
    long length = ifs.tellg();
    //cout << length << endl;
    
    char* pdata = new char[length]();
    //将文件游标偏移到文件开始位置再进行读取
    ifs.seekg(0);
    ifs.read(pdata,length);
    cout << pdata << endl;

    ifs.close();
}

int main(void)
{
    test0();
    return 0;
}

