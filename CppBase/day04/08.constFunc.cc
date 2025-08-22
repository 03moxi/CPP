#include <iostream>
using std::cout;
using std::endl;

class Point {
public:
    Point(int x,int y,int z)
    :_ix(x)
    ,_iy(y)
    ,_pint(new int(z))
    {
        cout << "Point(int,int)" << endl;
    }

    ~Point(){
        cout << "~Point()" << endl;
    }

    //this指针变成了双重const限定的指针
    void print() const
    {
        //const成员函数中不允许对数据成员进行修改
        //_ix = 1; //error
        cout << "(" << this->_ix 
            << "," << this->_iy
			<< ")" << endl;
        cout << "print const" << endl;
        cout << endl;

        //const成员函数中不能修改指针成员的指向
        //但是可以修改指针成员所指向的值
        //*_pint = 100;
        //_pint = new int();error
    }

    void print()
	{
		cout << "(" << this->_ix
            << "," << this->_iy
			<< ")" << endl;
        cout << "print" << endl;
        cout << endl;
        *_pint = 100; //error
        _pint = new int(); //ok
	}

private:
    int _ix;
    int _iy;
    int* _pint;
};


void test0(){
    const Point pt(1,2,3);
    pt.print();
    /* pt.setX(10); */
    /* pt._ix = 20; */

    Point pt2(19,30,40);
    /* pt2.setX(29); */
    pt2.print();
}

int main(void)
{
    test0();
    return 0;
}

