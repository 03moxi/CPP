#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::istringstream;

void readConfig(const string & filename){
    ifstream ifs(filename);
    if(!ifs.good()){
        cout << "open file fail!" << endl;
        return;
    }
    string line;
    string key,value;
    //从文件中读取一行的内容保存到line
    while(getline(ifs,line)){
        //创建字符串输入流对象，接收line的内容
        istringstream iss(line);
        //从iss对象的缓冲区输入内容给key和value
        iss >> key >> value;
        cout << key << " -----> " << value << endl;
    }
}


void test0(){
    readConfig("myserver.conf");
}

int main(void)
{
    test0();
    return 0;
}

