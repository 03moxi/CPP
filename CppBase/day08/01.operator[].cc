#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

//需求：自定义一个类模拟char数组
class CharArray{
public:
    CharArray(const char * pstr)
    : _capacity(strlen(pstr) + 1)
    , _data(new char[_capacity]())
    {
        strcpy(_data,pstr);
    }

    ~CharArray(){
        if(_data){
            delete [] _data;
            _data = nullptr;
        }
    }

    void print() const{
        cout << _data << endl;
    }

    //第一个const的效果，函数的返回值是一个const引用
    //调用函数得到结果不允许进行写操作
    //第二个const的效果，在函数中不能修改数据成员
    //const对象只能调用const成员函数
    const char & operator[](size_t idx) const{
        if(idx < _capacity - 1){
            /* _capacity = 100; */
            /* _data = new char[100](); */
            //_data[idx] = 'Y';  //可以修改
            return _data[idx];
        }else{
            cout << "out of range" << endl;
            static char nullchar = '\0';
            return nullchar;
        }
    }
private:
    size_t _capacity;
    char * _data;
};

void test0(){
    char arr[6] = "hello";
    cout << arr[0] << endl;
    arr[0] = 'H';
    cout << arr << endl;


    CharArray ca("hello");
    //ca[0]
    //ca.operator[](0)
    cout << ca[0] << endl;//读操作
    /* ca[0] = 'H';//写操作 */
    ca.print();

    const CharArray ca2("world");
    cout << ca2[0] << endl;
    cout << ca2.operator[](0) << endl;
    /* ca2[0] = 'W'; */
    ca2.print();
}

int main(void){
    test0();
    return 0;
}
