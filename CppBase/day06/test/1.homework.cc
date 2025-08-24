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
        strcpy(_brand,brand);
        cout << "Computer(const char*,double)" << endl;
    }

    void destory(){
        delete this;
    }
    
    void print(){
        cout << _brand << " " << _price << endl;
    }

private:
    ~Computer(){
        if(_brand){
            delete [] _brand;
            _brand = nullptr;
        }
        cout << "~Computer()" << endl;
    }
    Computer(const Computer & rhs) = delete;
    Computer & operator = (const Computer & rhs) = delete;

private:
    char* _brand;
    double _price;

};


void test0(){
    Computer* pc = new Computer("apple",20000);
    pc->print();
    pc->destory();
}

int main(void)
{
    test0();
    return 0;
}

