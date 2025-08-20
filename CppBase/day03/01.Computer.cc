#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

//定义类名遵循大驼峰规则
class Computer{
public:
    //构造函数
    Computer(){
        cout << "computer()" << endl;
    }
    //类提供给外界的接口，告知了可以进行哪些操作
    //定义成员函数遵循小驼峰规则
    void setBread(const char *brand)
    {
        strcpy(_brand,brand);
    }
    void setPrice(float price)
    {
        _price = price;
    }
    void print(){
        cout << "brand:" << _brand << endl;
        cout << "price:" << _price << endl;
    }
private:
    //定义数据成员前面加下划线
    char _brand[20];
    float _price;

};

void test0(){
    Computer pc;
    pc.setBread("Xiaomi");
    pc.setPrice(5699);
    pc.print();
}

int main(void)
{
    test0();
    return 0;
}

