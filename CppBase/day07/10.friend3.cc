#include <math.h>
#include <iostream>
using std::cout;
using std::endl;

class Point {
public:
    Point(int x,int y)
    :_ix(x)
    ,_iy(y)
    {}
    
     void print() const{
        cout << "(" << _ix
            << "," << _iy
            << ")" << endl;
    }

    //声明了Line类是Point类的友元类
    friend class Line;

private:
    int _ix;
    int _iy;
};

class Line {
public:
    float distance(const Point & lhs, const Point & rhs);
    void setX(Point & rhs,int x){
        rhs._ix = x;
    }
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

    l.setX(pt,1);
    pt.print();

}

int main(void)
{
    test0();
    return 0;
}

