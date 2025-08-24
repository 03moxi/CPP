#include <math.h>
#include <iostream>
using std::cout;
using std::endl;

class Point;

class Line {
public:
    //友元的成员函数形式
    float distance(const Point & lhs, const Point & rhs);
};

class Point {
public:
    Point(int x,int y)
    :_ix(x)
    ,_iy(y)
    {}

    friend float Line::distance(const Point & lhs, const Point & rhs);
private:
    int _ix;
    int _iy;
};

float Line::distance(const Point & lhs, const Point & rhs){
    return sqrt(pow(lhs._ix - rhs._ix,2) + 
                pow(lhs._iy - rhs._iy,2));
}
void test0(){
    Point pt(0,0);
    Point pt2(3,4);
    Line l;
    cout << l.distance(pt,pt2) << endl;
}

int main(void)
{
    test0();
    return 0;
}

