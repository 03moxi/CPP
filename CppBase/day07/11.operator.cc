#include <iostream>
using std::cout;
using std::endl;

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
    friend
    Complex operator+(const Complex & lhs,const Complex & rhs);
private:
    int _real;
    int _image;
};

Complex operator+(const Complex & lhs,const Complex & rhs){
    return Complex(lhs._real + rhs._real,
                   lhs._image + rhs._image);
}

void test0(){
    Complex c1(1,2);
    Complex c2(3,4);
    Complex c3 = c1 + c2;
    Complex c4 = operator+(c1,c2);//本质
    c3.print();
    c4.print();
}

int main(void)
{
    test0();
    return 0;
}

