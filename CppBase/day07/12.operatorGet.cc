#include <iostream>
using std::cout;
using std::endl;

class Complex
{
public:
    Complex(int real,int image)
    : _real(real)
    , _image(image)
    {}

    void print() const{
        cout << _real << "+"
            << _image << "i"
            << endl;
    }
    int getReal() const{
        return _real;
    }

    int getImage() const{
        return _image;
    }
private:
    int _real;
    int _image;
};

Complex operator+(const Complex & lhs, const Complex & rhs){
    return Complex(lhs.getReal() + rhs.getReal(),
                   lhs.getImage() + rhs.getImage());
}

void test0(){
    Complex c1(1,2);
    Complex c2(3,4);
    /* c1 = c2; */
    Complex c3 = c1 + c2;
    Complex c4 = operator+(c1,c2);//本质
    c3.print();
    c4.print();

    /* Complex c5 = Complex(2,6); */

    /* int num = 1,num2 = 2; */
    /* num + num2; */
}

int main(void){
    test0();
    return 0;
}
