#include <iostream>
using std::cout;
using std::endl;

class Singleton {
public:
    static Singleton* getInstance(){
        if(_pInstance == nullptr){
            _pInstance = new Singleton();
        }
        return _pInstance;
    }
    
    void init(int x,int y){
        _ix = x;
        _iy = y;
    }

    static void destroy(){
        if(_pInstance){
            delete _pInstance;
            _pInstance = nullptr;
        }
    }

    void print()
	{
		cout << "(" << this->_ix 
            << "," << this->_iy
			<< ")" << endl;
	}

private:
    //默认的特殊成员函数（构造函数、析构函数、拷贝构造函数、拷贝赋值运算符、移动构造函数、移动赋值运算符）。
    Singleton() = default;
    Singleton(int x,int y)
    :_ix(x)
    ,_iy(y)
    {
        cout << "Singleton(int,int)" << endl;
    }

    ~Singleton(){
        cout << "~Singleton()" << endl;
    }

    //C++11之后的写法
    //表示从这个类中删除这个函数
    Singleton(const Singleton & rhs) = delete;
    Singleton & operator = (const Singleton & rhs) = delete;

private:
    int _ix;
    int _iy;
    static Singleton* _pInstance;

};

Singleton* Singleton::_pInstance = nullptr;

void test0(){
    Singleton::getInstance()->init(3,9);
    Singleton::getInstance()->print();
    Singleton::getInstance()->init(30,90);
    Singleton::getInstance()->print();
    Singleton::getInstance()->init(300,900);
    Singleton::getInstance()->print();
    Singleton::destroy();
}

int main(void)
{
    test0();
    return 0;
}

