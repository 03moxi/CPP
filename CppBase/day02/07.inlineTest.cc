#include <iostream>
using std::cout;
using std::endl;

#define MAX(a, b) ((a) > (b) ? (a) : (b)) //ok

void test0(){
    //20和10比大小，20比较大返回本身
    int result = MAX(20,10) + 20;//result的值是多少？

    //10和20比大小，20比较大返回20 + 20
    int result2 = MAX(10,20) + 20;//result2的值是多少？

    cout << "result:" << result << endl;
    cout << "result2:" << result2 << endl;
}

void test1(){
//使用MAX的代码段经过预处理器扩展后，result = ((i++) > (j) ? (i++):(j));
    int i = 4,j = 3;
    int result = MAX(i++,j);
    cout << result << endl;//result = 5；
    cout << i << endl; //i = 6;
}

inline void max(int x,int y){
     cout << x + y << endl;
}

void test2(){
    /* cout << max(10,20) + 20 << endl; */
    max(10,20);
    //就被替换成 inline函数体中的内容
    max(11,45);
}

int main(void)
{
    test0();
    return 0;
}

