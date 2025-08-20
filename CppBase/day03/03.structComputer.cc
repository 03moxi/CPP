#include <string.h>
#include <iostream>
using std::cout;
using std::endl;


//定义类名遵循大驼峰规则
struct Computer{

    void setBrand(const char* brand)
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

    char _brand[20];
    float _price;
};



void test0(){
    Computer pc;
    pc.setBrand("Xiaomi");
    pc.setPrice(5699);
    pc.print();
    cout << pc._price << endl;
    pc._price = 1;
    cout << pc._price << endl;
}

int main(void)
{
    test0();
    return 0;
}

