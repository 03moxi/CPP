#include <iostream>
using std::cout;
using std::endl;

class Point {
public:
    Point(int x,int y)
    :_ix(x)
    ,_iy(y)
    ,_iz(_ix)
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
            << "," << this->_iz
			<< ")" << endl;
    }

private:
    int _ix;
    int _iy;
    int & _iz;
};


void test0(){
    Point pt(1,2);
    pt.print();
    cout << sizeof(Point) << endl;
}

int main(void)
{
    test0();
    return 0;
}

