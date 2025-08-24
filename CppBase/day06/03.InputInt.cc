#include <iostream>
#include <limits>
using std::cout;
using std::endl;
using std::cin;

void InputInteger(int num){
    cout << "请输入一个int型数据" << endl;
    //逗号表达式整体的值为最后一个逗号之后的表达式的值
    while(cin >> num,!cin.eof()){
        if(cin.bad()){
            cout << "cin has broken!" << endl;
            return;
        }else if(cin.fail()){
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            cout << "请输入一个int型数据" << endl;
        }else{
            //输入是合法的
            cout << "num:" << num << endl;
            break;
        }
    }
}

void test0(){
    int num = 0;
    InputInteger(num);
}

void test1(){
    int number = 10;
    int number2 = 20;

    //if(cin.good()){
    if(cin){
        cout << "hello" << endl;
    }

    //cin >> number这个表达式的返回值就是cin
    //cin对象是good状态时就可以视为true,还可以继续正常工作
    cin >> number >> number2;
    cout << number << endl;
    cout << number2 << endl;
}

int main(void)
{
    test1();
    return 0;
}

