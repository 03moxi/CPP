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

    Computer(const Computer & rhs)
    //: _brand(rhs._brand) //_brand = rhs._brand;
    : _brand(new char[strlen(rhs._brand) + 1]())
    , _price(rhs._price)
    {
        strcpy(_brand,rhs._brand);
        cout << "Computer(const Computer&)" << endl;
        /* rhs._price = 1; */
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

void test0(){
    Computer pc("Apple",20000);
    pc.print();

    Computer pc2 = pc;
    pc2.print();

    cout << endl;
    //有时需用通过拷贝构造复制临时对象的内容
    Computer pc3 = Computer("ASUS",5000);
    pc3.print();
    cout << endl;
}

//拷贝构造的第二种调用时机
//函数参数改成引用，可以避免复制
void func(Computer &rhs){
    rhs.print();
}

void test1(){
    Computer pc("apple",20000);
    func(pc);
}

//拷贝构造的第三种调用时机
Computer pc3("Acer",5400);

Computer & func2(){
    return pc3;
}

void test2(){
    func2();
}


int main(void)
{
    test1();
    return 0;
}

