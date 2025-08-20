#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Computer{
public:
    Computer(const char * brand,double price)
    : _brand(new char[strlen(brand) + 1]())
    , _price(price) // _price = price;
    {
        cout << "Computer(const char *,double)" << endl;
        strcpy(_brand,brand);
    }

    //析构函数是用来清理数据成员所申请的堆空间资源的
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
    char * _brand;
    double _price;
};

int a = 100;

Computer pc1("huawei",6000);


void test0(){
    Computer pc("Apple",20000);
    cout << sizeof(pc) << endl;
    pc.print();

    static Computer pc2("Dell",5000);

    int *p = new int(10);
    delete p;
    p = nullptr;

    Computer *p1 = new Computer("Lenove",6500);
    p1->print();
    delete p1;
    p1 = nullptr;
}

int main(void)
{
    test0();
    return 0;
}

