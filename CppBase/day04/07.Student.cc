#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Student{
public:
    Student(int id,const char *name)
    :_id(id)
    ,_name(new char[strlen(name) + 1]())
    {
        strcpy(_name,name);
        cout << "Student()" << endl;
    }

    ~Student()
    {
        if(_name){
            delete []_name;
            _name = nullptr;
        }
        cout << "~Student()" << endl;
    }

public:
    void *operator new(size_t sz)
    {
        cout << "operator new" << endl;
        void* ret = malloc(sz);
        return ret;
    }
    
    void operator delete(void * pointer)
	{
        cout << "operator delete" << endl;
		free(pointer);
	}

    void print() const
	{
		cout << "id:" << _id << endl
			<< "name:" << _name << endl;
	}

private:
    int _id;
    char* _name;
};

void test0(){
    Student * stu = new Student(100, "Jackie");
	stu->print();
    delete stu;
    stu = nullptr;
}

void test1(){
    /* Student stu(190,"bob"); */
    Student * pstu = new Student(100,"tom");
    /* delete pstu; */
}

int main(void)
{
    test1();
    return 0;
}

