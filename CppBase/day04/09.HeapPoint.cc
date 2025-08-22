#include <iostream>
using std::cout;
using std::endl;

class Point {
public:
    Point(){ cout << "Point()" << endl; }
    
    Point(int x,int y)
    :_ix(x)
    ,_iy(y)
    {
        cout << "Point(int,int)" << endl;
    }

    ~Point(){
        cout << "~Point()" << endl;
    }

    void print() const
    {
        cout << "(" << this->_ix
             << "," << this->_iy
             << ")" << endl;
        cout << "print const" << endl;
        cout << endl;
    }

    void print()
    {
        cout << "(" << this->_ix
            << "," << this->_iy
			<< ")" << endl;
        cout << "print" << endl;
        cout << endl;
    }

private:
    int _ix = 10;
    int _iy = 10;
};


void test0(){
    Point* pt = new Point();

    Point* pt1 = new Point(11,12);
    pt1->print();
    delete pt1;
    pt1 = nullptr;

    Point* pt2 = new Point[5]();
    pt2->print();
    (pt2 + 1)->print();
    pt2 = nullptr;
}

int main(void)
{
    test0();
    return 0;
}

