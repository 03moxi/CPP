#include <iostream>
using std::cout;
using std::endl;

class Point{
public:
    //这个关键字加到隐式转换时需要调用的构造函数前
    //禁止隐式转换
    explicit
    Point(int x=0,int y=0)
    :_ix(x)
    ,_iy(y)
    { cout << "Point(int,int)" << endl; }

    void print() const{
        cout << "(" << _ix
            << "," << _iy
            << ")" << endl;
    }

private:
    int _ix;
    int _iy;
};


void test0(){
    Point pt(1,2);
    Point pt2(10);
    Point pt3;
    Point pt4 = Point(2,6);
    Point pt5 = Point();
    
    Point(); //利用无参构造创建一个临时Point对象

    //隐式转换
    //Point pt6 = Point(1);
    //Point pt6 = 1;
    /* pt6.print(); */

    //这样写实际上是声明了一个返回类型Point的函数
    //Point pt3();
    //pt3.print();
}

int main(void)
{
    test0();
    return 0;
}

