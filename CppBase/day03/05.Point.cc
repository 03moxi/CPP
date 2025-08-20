#include <iostream>
using std::cout;
using std::endl;

class Point {
public:
    Point(){
        cout << "Point()" << endl;
    }

    Point(int x)//函数参数列表
    :_ix(x)//初始化列表
    ,_iy(100)//初始化列表
    {
        cout << "Point(int)" << endl;
    }

    //初始化列表的形式，严格意义上的初始化
    Point(int x,int y)
    :_ix(x)
    ,_iy(y)
    {
        cout << "Point(int,int)" << endl;
    }

    Point(const Point &rhs)
    :_ix(rhs._ix)
    ,_iy(rhs._iy)
    {
        cout << "Point(int,int)" << endl;
    }
    
    ~Point(){
        cout << "~Point()" << endl;
    }

    void print(){
        cout << "(" << _ix
             << "," << _iy
             << ")" << endl;
    }


private:
    int _ix = 100;//C++11之后允许的
    int _iy = 200;

};


void test0(){
    Point pt;//创建对象时就会自动调用构造函数
    pt.print();

    cout << endl;

    Point pt2(1,2);
    pt2.print();

    cout << endl;

    Point pt3(100);
    pt3.print();
}

int main(void)
{
    test0();
    return 0;
}

