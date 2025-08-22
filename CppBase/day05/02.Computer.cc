#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Computer{
public:
    static Computer* getInstance(){
        if(_pInstance == nullptr){
            _pInstance = new Computer("apple",20000);
        }
        return _pInstance;
    }

    void init(const char* brand,double price){
        if(_brand){
            delete [] _brand;
            _brand = nullptr;
        }
        _brand = new char[strlen(brand) + 1]();
        strcpy(_brand,brand);
        _price = price; 
    }

    static void destroy(){
        if(_pInstance){
            delete _pInstance;
            _pInstance = nullptr;
        }
        cout << "heap delete" << endl;
    }

    void print(){
        cout << "brand:" << _brand << endl;
        cout << "price:" << _price << endl;
    }

private:
    Computer() = default;
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
    
    Computer(const Computer & rhs) = delete;
    Computer & operator = (const Computer & rhs) = delete;

private:
    char* _brand;
    double _price;
    static Computer* _pInstance;

};

Computer* Computer::_pInstance = nullptr;

void test0(){
    Computer::getInstance()->print();
    Computer::getInstance()->init("apple",10000);
    Computer::getInstance()->init("apple",10000);
    Computer::destroy();
}

int main(void)
{
    test0();
    return 0;
}

