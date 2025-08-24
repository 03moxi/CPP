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

    Complex operator+(const Complex & rhs){
        return Complex(_real + rhs._real,
                       _image + rhs._image);
    }

    Complex & operator+=(const Complex & rhs){
        cout << "operator+=" << endl;
        _real += rhs._real;
        _image += rhs._image;
        return *this;
    }
private:
    int _real;
    int _image;
};


void test0(){
    Complex c1(1,2);
    Complex c2(3,4);
    Complex c3 = c1 + c2;
    c3.print();

    c3 += c1;
    c3.operator+=(c1);
    c3.print();
}

int main(void){
    test0();
    return 0;
}
