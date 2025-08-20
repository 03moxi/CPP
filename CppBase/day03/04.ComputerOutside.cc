#include <string.h> //c语言头文件放在最上，如果有自定义头文件放在最上
#include <iostream> //其次是C++的头文件，第三方库头文件放在最下
using std::cout;
using std::endl;

class Computer {
public:
    //成员函数
    void setBrand(const char *brand);//设置品牌

    void setPrice(float price);//设置价格

    void print();
private:
    //数据成员
    char _brand[20];
    float _price;

};

//虽然成员函数的定义放在了类之外
//但由于作用域限定，仍视为类中
//返回类型  类名::成员函数

void Computer::setBrand(const char *brand){
    strcpy(_brand,brand);
}

void Computer::setPrice(float price){
    _price = price;
}

void Computer::print(){
    cout << "brand:" << _brand << endl;
    cout << "price:" << _price << endl;
}

void test0(){
    Computer pc;
    pc.setBrand("Apple");
    pc.setPrice(12000);
    pc.print();
}

int main(void)
{
    test0();
    return 0;
}

