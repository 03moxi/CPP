#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;

void test0(){
    string str("wangdao");

    //1.下标方式进行遍历
    for(size_t i = 0;i < str.size();++i){
        cout << str[i] << " ";
    }
    cout << endl;

    //2.增强for循环
    //通常与auto关键字在一起使用
    //auto能够自动推导出类型
    //&表示引用，直接操作元素本身
    //如果不加引用，操作的是元素的副本
    for(auto & ch : str){
        cout << ch << " ";
    }
    cout << endl;

    //3.迭代器方式
    //迭代器在目前阶段就理解成广义的指针
    //auto it = str.begin();
    string::iterator it = str.begin();
    while(it != str.end()){
        cout << *it << " ";
        ++it;
    }
    cout << endl;

    auto it2 = str.begin();
    auto it3 = str.end();
    string str2(it2,it3);
    cout << str2 << endl;
}

int main(void)
{
    test0();
    return 0;
}

