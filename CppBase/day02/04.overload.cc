#include <iostream>
using std::cout;
using std::endl;

int add(int x,int y){
    return x + y;
}

//int add(int y,int x){ //error
//    return y + x;
//}

#ifdef _cplusplus
extern "c"{
#endif

int add(int x,int y,int z){
    return x + y + z;
}
float add(float x,int y){
    return x + y;
}

#ifdef _cplusplus
}
#endif

float add(int x,float y){
    return x + y;
}

//void add(int x,int y){
//    return x + y;
//}

void test0(){
    int a = 1, b =2, c = 3;
    float d =1.2;
    cout << add(a,b) << endl;
    cout << add(a,b,c) << endl;
    cout << add(d,b) << endl;
    cout << add(c,d) << endl;
    add(a,b);
}

int main(void)
{
    test0();
    return 0;
}

