#include <iostream>
using std::cout;
using std::endl;
class Stack {
public:
    Stack(int size = 10)
    :_size(size)
    ,_top(-1)
    ,_data(new int[_size]())
    {}
    
    ~Stack(){
        if(_data){
            delete [] _data;
            _data = nullptr;
        }
    }
    
    bool empty();   //判断栈是否为空
    bool full();    //判断栈是否已满
    void push(int); //元素入栈
    void pop();     //元素出栈
    int top();      //获取栈顶元素

private:
    int _size;
    int _top;
    int* _data;
};

bool Stack::empty(){
    return _top == -1;
}

bool Stack::full(){
    return (_top == _size - 1);
}

void Stack::push(int value){
    if(!full()){
        _data[++_top] = value;
    }else{
        cout << "The Stack is full" << endl;
    }
}

void Stack::pop(){
    if(!empty()){
        --_top;
    }else{
        cout << "The Stack is empty" << endl;
    }
}

int Stack::top(){
    return _data[_top];
}

void test0(){

}

int main(void)
{
    test0();
    return 0;
}

