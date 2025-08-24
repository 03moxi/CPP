#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class String {
public:
    String():_str(new char[1]()){}

    String(const char* pstr)
        :_str(new char[strlen(pstr) + 1]())
    {
        strcpy(_str,pstr);
        cout << "String(const char*)" << endl;
    }

    void print(){
        cout << _str << endl;
    }
    
    ~String(){
        if(_str){
            delete [] _str;
            _str = nullptr;
        }
        cout << "~String" << endl;
    }

    String(const String & rhs)
    :_str(new char[strlen(rhs._str) + 1]())
    {
        strcpy(_str,rhs._str);
        cout << "String(const String & rhs)" << endl;
    }

    String & operator = (const String & rhs){
        if(this != &rhs){
            delete [] _str;
            _str = new char[strlen(rhs._str) + 1]();
            strcpy(_str,rhs._str);
        }
        cout << "String operator = (const String & rhs)" << endl;
        return *this;
    }

private:
    char* _str;
};


void test0(){
    String str;
    String str1("aqqle");
    str1.print();
    cout << endl;
    String str2 = str1;
    str2.print();
    cout << endl;
    str = str2;
    str.print();

}

int main(void)
{
    test0();
    return 0;
}

