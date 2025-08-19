#include <iostream>
using std::cout;
using std::endl;

void test0(){
    int *p = (int *)malloc(sizeof(int));
    *p = 10;
    free(p);

    int * p1 = new int();//初始化为该类型的默认值
    cout << *p1 << endl;
    delete p1;
    //这个写法存在隐患
    //因为其他的程序可能将数据存到了这片空间
    //但是p1还是指向这片空间，有可能造成篡改
    //cout << *p1 << endl;
    p1 = nullptr;//安全回收

    int *p2 = new int(10);//初始化为传入的参数值
    cout << *p2 << endl;
    delete p2;



//#if 0
    //10代表数组要存放的元素个数
    //写上小括号，确保了对申请的这片空间进行了初始化
    int *p3 = new int[10]();
    for(int idx = 0; idx < 10; ++idx){
        cout << p3[idx] << endl;
    }
    delete [] p3;
    cout << endl;

    //new申请数组空间，如果确定好要存放的元素
    //可以采用初始化列表
    //大括号包含要初始化的元素
    //如果写了小括号，不能往里面传参数
    int *p4 = new int[3]{1,2,3};
    for(int idx = 0; idx < 3; ++idx){
        cout << p4[idx] << endl;
    }
    delete [] p4;

//#endif


}

int main(void)
{
    test0();
    return 0;
}

