#include <iostream>
using std::cout;
using std::endl;

//可以理解为，在单一的源文件中
//匿名空间中定义的实体类似于定义在全局位置的实体
namespace {


//在C++中可以直接使用的C语言的函数
//都已经定义在匿名空间中了
//如果人为地在匿名空间重新定义
//在调用时会有新的逻辑
//不建议这样改写，会造成混乱
void printf(const char * str,int a){
    cout << str << endl;
    cout << a << endl;
}

int num = 10;

void func(){
    cout << "func()" << endl;
}
}



void test0(){
    int num = 11;
    cout << num << endl;
    func();
    printf("%d\n",num);
}

int main(void)
{
    test0();
    return 0;
}

