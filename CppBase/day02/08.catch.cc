#include <iostream>
using std::cout;
using std::endl;

double division(double x,double y){
    if(y == 0){
        throw y;
    }
    return x/y;
}

void test0(){
    int x = 100, y = 0;
    try{
        cout << division(x,y) << endl;
    }catch(double x){
        cout << "double" << endl;
    }catch(int x){
        cout << "int" << endl;
    }
}

int main(void)
{
    test0();
    return 0;
}

