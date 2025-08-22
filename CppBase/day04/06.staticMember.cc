#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Computer {
public:
    Computer(const char* brand,double price)
        :_brand(new char[strlen(brand) + 1]())
         ,_price(price)
    {
        _totalPrice += _price;
        cout << "Computer(const char *,double)" << endl;
        strcpy(_brand,brand);
    }

    ~Computer(){
        if(_brand){
            delete _brand;
            _brand = nullptr;
            _totalPrice -= _price;
        }
        cout << "~Computer()" << endl;
    }

    Computer(const Computer &rhs)
    :_brand(new char[strlen(rhs._brand) + 1]())
    ,_price(rhs._price)
    {
        strcpy(_brand,rhs._brand);
        _totalPrice += _price;
        cout << "Computer(const Computer&)" << endl;
    }

    Computer & operator = (const Computer &rhs)
    {
        if(this != &rhs){
            _totalPrice -= _price;
            _totalPrice += rhs._price;

            delete [] _brand;
            _brand = new char[strlen(rhs._brand)+1]();
            strcpy(_brand,rhs._brand);
            _price = rhs._price;
            cout << "Computer & operator=(const Computer&)" << endl;
        }
        return *this;
    }

    void print(){
        cout << "brand:" << _brand << endl;
        cout << "price:" << this->_price << endl;
    }

    static void printTotalPrice(){
        //在静态成员函数中不能直接访问非静态成员
        /* cout << "price:" << _price << endl; */
        cout << "totalPrice:" << _totalPrice  << endl;
    }

private:
    char* _brand;
    double _price;
    static double _totalPrice;
};

double Computer::_totalPrice = 0;

void test0(){
    Computer pc("Apple",20000);
    Computer pc2("XiaoMi",6000);
    Computer pc3("Huawei",8000);
    pc = pc2;

    //pc.printTotalPrice();
    //类名::的方式调用静态函数，更为常用
    Computer::printTotalPrice();

    pc3.print();
    cout << endl;
    //static数据成员不依赖于特定的对象
    //被所有的Computer类对象共享
    //访问时也可以通过类名::
}

int main(void)
{
    test0();
    return 0;
}

