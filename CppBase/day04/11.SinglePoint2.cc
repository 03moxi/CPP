#include <iostream>
using std::cout;
using std::endl;

class Point {
    Point(int x,int y)
    :_ix(x)
    ,_iy(y)
    {
        cout << "Point(int,int)" << endl;
    }

    ~Point(){
        cout << "~Point()" << endl;
    }

    Point(const Point & rhs) = delete;
    Point & operator=(const Point& rhs) = delete;

public:
    static Point* getInstance(){
        if(_pInstance == nullptr){
            _pInstance  = new Point(1,2);
        }
        return _pInstance;
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
    int _ix;
    int _iy;
    static Point * _pInstance;
};

Point * Point::_pInstance = nullptr;
void test0(){
    //单例模式的规范
    Point::getInstance()->print();
    /* Point::getInstance()->destroy(); */
    Point::destroy();
}

int main(void)
{
    test0();
    return 0;
}

