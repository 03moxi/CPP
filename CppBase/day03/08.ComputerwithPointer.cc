#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Computer{
public:
    Computer(const char *brand,double price)
    :_brand(new char[strlen(brand) +1]())
    ,_price(price)// _price = price;
    {
        strcpy(_brand,brand);
        cout << "Computer(const char *,double)" << endl;
    }

    //析构函数是用来清理数据成员所申请的堆空间
    //默认的析构函数并不能实现这个功能
    //需要我们自己定义析构函数的内容
    //析构函数是提供给我们的接口，用来清理
    ~Computer(){
        if(_brand){
            delete [] _brand;
            _brand = nullptr;
        }
        cout << "~Computer()" << endl;
    }

    void print(){
        cout << "brand:" << _brand << endl;
        cout << "price:" << _price << endl;
    }

private:
    char *_brand;
    double _price;
};


void test0(){
    Computer pc("Apple",20000);
    cout << sizeof(pc) << endl;
    pc.print();
    //手动调用一次析构后
    //当pc被销毁时，还会自动调用一次析构
    pc.~Computer();
    pc.print();
}

void test1(){
    const char *p = "hello";
    cout << sizeof(*p) << endl;
    cout << sizeof(p) << endl;
    cout << strlen(p) << endl;
}

void test2(){
    const char *p = "hello";
    cout << p << endl;

    char *p2 = new char[6]();
    strcpy(p2,p);
    cout << p2 << endl;

    char *p3 = nullptr;
    cout << p3 << endl;

    cout << "hello" << endl;
}

int main(void)
{
    test2();
    return 0;
}

