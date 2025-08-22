#include <iostream>
using std::cout;
using std::endl;

class Point {
    Point(int x,int y)
    :_ix(x)
    ,_iy(y)
    {
        cout << "Point(int,int)" << endl;
    }

    Point(const Point & rhs) = delete;
    Point & operator=(const Point& rhs) = delete;

public:
    static Point & getInstance(){
        static Point pt(1,2);
        return pt;
    }
    
    ~Point(){
        cout << "~Point()" << endl;
    }
    
    void print()
	{
		cout << "(" << this->_ix
            << "," << this->_iy
			<< ")" << endl;
	}

private:
    int _ix;
    int _iy;
};


void test0(){
    Point & pt = Point::getInstance();
    Point & pt2 = Point::getInstance();
    cout << &pt << endl;
    cout << &pt2 << endl;
}

int main(void)
{
    test0();
    return 0;
}

