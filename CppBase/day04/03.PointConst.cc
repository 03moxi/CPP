#include <iostream>
using std::cout;
using std::endl;

class Point {
public:
    Point(int x,int y)
    //const数据成员需在初始化列表中进行初始化
    :_ix(x)
    ,_iy(y)
    {
        //因为数据成员被const修饰
        //_ix = x;
        //_iy = y;
        cout << "Point(int,int)" << endl;
    }

    Point(const Point &rhs)
    :_ix(rhs._ix)
    ,_iy(rhs._iy)
    {
        cout << "Point(const Point &)" << endl;
    }

    //不能对const数据成员进行赋值操作
    //应该在初始化是确定其值
    
#if 0
    //成员函数的参数列表首位会被编译器自动加上一个参数：this指针
    //作用：指向本对象，准确访问本对象的成员
    //形式：Point * const this
    //位置：成员函数参数列表首位，不能显式写出
    Point &operator = (const Point &rhs){
        this->_ix = rhs._ix;
        this->_iy = rhs._iy;
        cout << "Point& operator=(const Point &)" << endl;
        return *this;//返回本对象
    }
#endif

    void print()
	{
		cout << "(" << this->_ix
            << "," << this->_iy
			<< ")" << endl;
	}

private:
    const int _ix;
    const int _iy;
};


void test0(){
    Point pt(1,2);
}

int main(void)
{
    test0();
    return 0;
}

