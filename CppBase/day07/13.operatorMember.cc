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

private:
    int _real;
    int _image;
};


void test0(){
    Complex c1(1,2);
    Complex c2(3,4);
    /* c1 = c2; */
    Complex c3 = c1 + c2;
    c3.print();

    Complex c4 = c1.operator+(c2);//本质
    c4.print();

    /* int num = 1,num2 = 2; */
    /* num + num2; */
}

int main(void){
    test0();
    return 0;
}
