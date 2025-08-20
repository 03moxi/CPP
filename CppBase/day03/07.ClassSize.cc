#include <iostream>
using std::cout;
using std::endl;

class Point {
public:
    //初始化列表的形式,严格意义上的初始化
    Point(int x,int y)
        :_ix(x)
         ,_iy(y)
    {
        cout << "Point(int,int)" << endl;
    }

    void print()
    {
        cout << "(" << _ix
            << "," << _iy
            << ")" << endl;
    }

    void func(){}
    void func2(){}
    void func3(){}
    void func4(){}

private:
    int _ix = 100;//C++11之后允许的
    int _iy = 200;
};

class C{
    int _c1;
    int _c2;
    double _c3;
};

class D{
    int _d1;
    double _d2;
    int _d3;
};

class E{
    double _e;
    char _eArr[20];
    double _e1;
    int _e2;
};

class F{
    char _fArr[20];
};

class G{
    char _gArr[20];
    char p;
    double _g2;
};

void test0(){
    cout << sizeof(Point) << endl;

    Point pt(1,2);
    cout << sizeof(pt) << endl;

}

void test1(){
    cout << sizeof(C) << endl;
    cout << sizeof(D) << endl;
    cout << sizeof(E) << endl;
    cout << sizeof(F) << endl;
    cout << sizeof(G) << endl;
}

int main(void)
{
    test1();
    return 0;
}

