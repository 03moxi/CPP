#include <iostream>
using std::cout;
using std::endl;

class Point {
public:
    Point(){
        cout << "Point" << endl;
    }

    Point(int x)
        :_ix(x)
         ,_iy(100)
    {
        cout << "Point(int)" << endl;
    }

    //初始化列表的形式,严格意义上的初始化
    Point(int x,int y);

    void print()
    {
        cout << "(" << _ix
             << "," << _iy
             << ")" << endl;
    }
private:
    int _ix = 100;
    int _iy = 200;
};

Point::Point(int x,int y)
    :_ix(x)
     ,_iy(y)
{
    cout << "Point(int,int)" << endl;
}

void test0(){

    Point pt;//创建对象时就会自动调用构造函数
    pt.print();

    Point pt2(1,2);
    pt2.print();

    Point pt3(100);
    pt3.print();
}

int main(void)
{
    test0();
    return 0;
}

