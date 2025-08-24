#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

//需求：自定义一个类模拟char数组
class CharArray {
public:
    CharArray(const char * pstr)
    :_capacity(strlen(pstr) + 1)
    ,_data(new char[_capacity]())
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

    char & operator[](size_t idx){
        return _data[idx];
    }

private:
     size_t _capacity;
     char* _data;
};

void test0(){
    char arr[6] = "hello";
    cout << arr[0] << endl;
    arr[0] = 'H';
    cout << arr << endl;


    CharArray ca("hello");
    cout << ca[0] << endl;
    ca[0] = 'H';
    ca.print();
}

int main(void)
{
    test0();
    return 0;
}

