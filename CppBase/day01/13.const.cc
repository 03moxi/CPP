#include <iostream>
using std::cout;
using std::endl;

#define MAX 100

void test0(){
    cout << MAX - 10 << endl;

    //cosnt int max = "hello";//error，因为const常量有类型检查
    const int max = 100;

    int num;
    num = 1000;
    //const int num2;//error，因为const常量有类型检查
    
    int const min = 0;
    cout << min << endl;
}

void test1(){
    int num = 10, num2 = 11;
    //const在星号前面，表示常量指针
    //指向一个常量的指针
    const int *p = &num;
    cout << *p << endl;
    //*p = 5; //不能通过解引用修改所指向的值
    p = &num2; //可以修改指向
    cout << *p << endl;
}

void test2(){
    int num = 10, num2 = 11;
    //const在星号前面，表示常量指针
    //指向一个常量的指针
    int const *p = &num;
    cout << *p << endl;
    //*p = 5;//不能通过解引用修改所指向的值
    p = &num2;//可以修改指向
    cout << *p << endl;
}

void test3(){
    int num = 10, num2 = 11;
    //const在星号后面，表示指针常量
    //是一个常量，一个指针特性的常量
    //只读属性施加在指针上
    int * const p = &num;
    cout << *p << endl;
    *p = 5;//能够通过解引用修改所指向的值
    //p = &num2;//不能修改指向
    cout << *p << endl;
}

//数组指针，指向一整个数组的指针
void test4(){
    int arr[5] = {1,2,3,4,5};
    int (*p)[5] = &arr;
    for(int i =0;i<5;++i){
        cout << (*p)[i] << endl;
    }
}

//指针函数，指是一个数组，元素都是指针
void test5(){
    int num = 5, num2 = 6, num3 = 7;
    int * p1 = &num;
    int * p2 = &num2;
    int * p3 = &num3;
    int *arr[3] = {p1,p2,p3};
    for(int i = 0; i < 3; ++i){
        cout << *arr[i] << endl;
    }
}




//函数指针
int add(int x, int y){
    return x + y;
}

void test6(){
    //函数指针定义和使用的完整形式
    int (*p)(int,int) = &add;
    cout << (*p)(7,8) << endl;

    //省略形式
    int (*p2)(int,int) = add;
    cout << p2(7,8) << endl;
}

//指针函数 返回类型为指针的函数
int Number = 600;

int *f(){
    int *p = &Number;
    return p;
}

void test7(){
    cout << *f() << endl;
}

int main(void)
{
    test0();
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    return 0;
}

