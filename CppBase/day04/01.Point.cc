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

    Point(const Point &rhs)
    :_ix(rhs._ix)
    ,_iy(rhs._iy)
    {
        cout << "Point(const Point &)" << endl;
    }

    //成员函数的参数列表首位会被编译器自动加上一个参数：this指针
    //作用：指向本对象，准确访问本对象的成员
    //形式：Point * const this
    //位置：成员函数参数列表首位，不能显式写出
    
    Point &operator = (const Point &rhs){
        _ix = rhs._ix;
        _iy = rhs._iy;
        cout << "Point& operator=(const Point &)" << endl;
        return *this;//返回本对象
    }
    
    ~Point(){
        cout << "~Point()" << endl;
    }
    
    void print()
    {
        //this本身就是一个指针，他已经是地址了
        //this是常量指针，它并不是对象，而是对象的地址
        //this是一个隐含的只读参数，在大多数现实中是存放阿仔寄存器或只读栈上
        //&this 拿到的是编译器生成的隐藏指针变量的地址，它不是标准语义所允许你使用的
        //cout << &this << endl;//error
        cout << this << endl;
        cout << "(" << this->_ix
             << "," << this->_iy
             << ")" << endl;
    }

private:
    int _ix;
    int _iy;
};



void test0(){
    Point pt(1,2);
    pt.print();
    cout << endl;

    cout << &pt << endl;

    cout << endl;

    Point pt2(3,4);
    pt2 = pt;//赋值操作
    //pt2.operator=(pt);//上一句的本质
    pt2.print();
    cout << endl;
    cout << &pt2 << endl;

    int a = 1,b = 2,c = 3;
    c = a = b;

    Point pt3(10,20);
    pt3 = pt2 = pt;
    pt3.print();

}

void test1(){
    Point *p = new Point(1,2);
    delete p;
    //现在p变成悬垂指针，悬垂指针并不是"空指针"
    //p还是原来的地址，只能那块内存已经变为“未定义”状态
    //编译器不会阻止你访问它(没有报错)
    //已经被清零或破坏了
    //继续使用p不正常，是未定义行为
    //正确写法 p = nullptr;
    p->print();
    (*p).print();
}


int main(void)
{
    test1();
    return 0;
}

