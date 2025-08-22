#include <iostream>
using std::cout;
using std::endl;

class Point {
public:
    Point(int x,int y)
    :_ix(x)
    ,_iy(y)
    {
        cout << "Point(int,int)" << endl;
    }

    ~Point(){
        cout << "~Point()" << endl;
    }

    void print()
    {
        cout << "(" << this->_ix
            << "," << this->_iy
			<< ")" ;
    }

private:
    int _ix;
    int _iy;
};

class Line {
public:
    Line(int x1,int y1,int x2,int y2)
    :_pt1(x1,y1)
    ,_pt2(x2,x2)
    {
        cout << "Line(int,int,int,int)" << endl;
    }

    ~Line(){
        cout << "~Line()" << endl;
    }

    void printLine(){
        _pt1.print();
        cout << " -----> " ;
        _pt2.print();
        cout << endl;
    }

private:
    //_pt1/_pt2是Line类的对象成员
    //生成Line类对象，
    //这个对象会包含两个Point类型的成员子对象
    Point _pt1;
    Point _pt2;
};



void test0(){
    Line line(1,2,3,4);
    line.printLine();
}

int main(void)
{
    test0();
    return 0;
}

