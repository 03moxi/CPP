#include <iostream>
#include <limits>
using std::cout;
using std::endl;
using std::cin;
using std::ostream;
using std::istream;

//第二个参数需要是引用形式，要确保写入的内容传给数据成员
void readInputInt(istream & is,int & number){
    cout << "please input a int number" << endl;
    //实际的输入操作在这里
    while(is >> number,!is.eof()){
        if(is.bad()){
            cout << "istream has broken" << endl;
            return;
        }else if(is.fail()){
            is.clear();
            is.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }else{
            break;
        }          
    }
}

class Complex {
public:
    Complex(int real,int image)
    :_real(real)
    ,_image(image)
    {}

    void print() const{
        cout << _real << "+"
            << _image << "i"
            << endl;
    }

    Complex & operator+=(const Complex & rhs){
        cout << "operator+=" << endl;
        _real += rhs._real;
        _image += rhs._image;
        return *this;
    }
    
    //前置++
    Complex & operator++(){
        cout << "operator++()" << endl;
        ++_real;
        ++_image;
        return *this;
    }

    //后置++运算符重载函数的参数列表中加入一个int
    //与前置++进行区分
    //返回类型是对象，不是引用
    Complex operator++(int){
        cout << "operator++(int)" << endl;
        Complex temp(*this);
        ++_real;
        ++_image;
        return temp;
    }
    
    //如果将<<运算符重载函数采用成员函数形式实现
    //那么第一个参数只能是Complex对象
    //与内置类型的使用方式不符
    /* ostream & operator<<(ostream & os){ */
    /*     os << _real << "+" << _image << "i" << endl; */
    /*     return os; */
    /* } */

    friend ostream & operator<<(ostream & os,const Complex & rhs);
    friend istream & operator>>(istream & is,Complex & rhs);

private:
    int _real;
    int _image;

};

ostream & operator<<(ostream & os,const Complex & rhs){
    os << rhs._real << "+" << rhs._image << "i";
    return os;
}

istream & operator>>(istream & is,Complex & rhs){
    cout << "please input a real:" << endl;
    /* is >> rhs._real; */
    readInputInt(is,rhs._real);
    cout << "please input an image:" << endl;
    /* is >> rhs._image; */
    readInputInt(is,rhs._image);
    return is;
} 

void test0(){
     Complex c1(1,2);
    cout << c1 << endl;
    operator<<(cout,c1) << endl;

    cin >> c1;
    cout << c1 << endl;

    /* c1 << cout; */
    /* c1.operator<<(cout); */


    /* int a = 1, b = 2; */
    /* //返回值就是cout */
    /* cout << a << b << endl; */

    /* //返回值就是cin */
    /* cin >> a >> b; */
}

int main(void)
{
    test0();
    return 0;
}

