#include <string>
#include <limits>
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::istream;

void checkStreamStatus(istream & is){
    cout << is.good() << endl;
    cout << is.bad() << endl;
    cout << is.fail() << endl;
    cout << is.eof() << endl;
}

void test0(){
    int num = 10;
    cout << "执行输入操作前检查流的状态" << endl;
    checkStreamStatus(cin);

    cout << endl;
    cin >> num;
    cout << "执行输入操作后检查流的状态" << endl;
    checkStreamStatus(cin);
    
    cout << endl;
    if(!cin.good()){
        //恢复流的状态
        cin.clear();
        //还需要清空缓冲区，才能继续使用
        //cin.ignore(1024,'\n');
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        checkStreamStatus(cin);
    }
    
    string line;
    cin >> line;
    cout << "line:" << line << endl;
    
    //没有进行正常输入，会将num设为0
    cout << "num:" << num << endl;
}

int main(void)
{
    test0();
    return 0;
}

