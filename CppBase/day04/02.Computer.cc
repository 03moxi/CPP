#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Computer{
public:
    Computer(const char* brand,double price)
    :_brand(new char[strlen(brand) + 1]())
    ,_price(price)
    {
        cout << "Computer(const char *,double)" << endl;
        strcpy(_brand,brand);
    }

    ~Computer(){
        if(_brand){
            delete [] _brand;
            _brand = nullptr;
        }
        cout << "~Computer()" << endl;
    }

    Computer(const Computer &rhs)
    :_brand(new char[strlen(rhs._brand)])
    ,_price(rhs._price)
    {
        strcpy(_brand,rhs._brand);
        cout << "Computer(const Computer&)" << endl;
    }

    Computer & operator = (const Computer &rhs)
    {
        //自定义的赋值运算符函数的流程
        //自我判读防止自我复制
        //删除原有资源，造成悬垂指针
        if(this != &rhs){
            delete [] _brand;//2.回收原本的空间
            _brand = new char[strlen(rhs._brand)+1]();//3.深拷贝
            strcpy(_brand,rhs._brand);//3
            _price = rhs._price;
            cout << "Computer & operator=(const Computer&)" << endl;
        }
        //如果是自我复制直接返回自己
        return *this;
    }

    void print(){
        cout << "_brand:" << _brand << endl;
        cout << "_price:" << _price << endl;
    }

private:
    char* _brand;
    double _price;
};

void test0(){
    Computer pc("Apple",20000);
    Computer pc2("XiaoMi",6000);
    Computer pc3("Huawei",8000);
    pc2 = pc;
    pc.print();
}

void test1(){
    Computer pc("Apple",20000);
    pc = pc;
    pc.print();
}

int main(void)
{
    test0();
    return 0;
}

