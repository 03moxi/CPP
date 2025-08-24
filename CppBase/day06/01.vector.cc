#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;

void test0(){
    long arr[5] = {1,2,3,4,5};

    //<>中是要存放的元素的类型
    vector<int> nums;
    vector<long> nums2;
    //无参构造创建的vector
    //其元素个数和容量都是0
    cout << "nums2'size:" << nums2.size() << endl;
    cout << "nums2'capacity:" << nums2.capacity() << endl;

    //传入一个参数10
    //这个参数代表元素有01个
    //容量也是10.存放了10个0(默认值)
    vector<long> nums3(10);
    cout << "nums3'size:" << nums3.size() << endl;
    cout << "nums3'capacity:" << nums3.capacity() << endl;

    for(size_t idx=0;idx<nums3.size();++idx){
        cout << nums3[idx] << " ";
    }
    cout << endl;

    //10个6
    vector<long> nums4(10,6);
    for(size_t idx=0;idx<nums4.size();++idx){
        cout << nums4[idx] << " ";
    }
    cout << endl;

    vector<int> nums5{1,2,3,4,5,6,7};
    for(auto & num : nums5){
        cout << num << " ";
    }
    cout << endl;

    //传入两个迭代器创建vector
    //左闭右开的区间
    //1,2,3,4
    /* vector<int>::iterator it = nums5.begin(); */
    vector<int> nums6(nums5.begin(),nums5.end() - 3);
    for(auto & num : nums6){
        cout << num << " ";
    }
    cout << endl;

    //这中构造方法，第一个参数是首迭代器
    //第二参数是尾后迭代器
    vector<long> nums7(arr,arr+5);
    for(auto & num : nums7){
        cout << num << " ";
    }
    cout << endl;

}

void test1(){
    vector<int> nums;
    nums.push_back(1);
    cout << "nums'size:" << nums.size() << endl;
    cout << "nums'capacity:" << nums.capacity() << endl;

    nums.push_back(2);
    cout << "nums'size:" << nums.size() << endl;
    cout << "nums'capacity:" << nums.capacity() << endl;
    
    nums.push_back(3);
    cout << "nums'size:" << nums.size() << endl;
    cout << "nums'capacity:" << nums.capacity() << endl;

    nums.push_back(4);
    cout << "nums'size:" << nums.size() << endl;
    cout << "nums'capacity:" << nums.capacity() << endl;
    nums.push_back(5);
    cout << "nums'size:" << nums.size() << endl;
    cout << "nums'capacity:" << nums.capacity() << endl;
    nums.push_back(6);
    cout << "nums'size:" << nums.size() << endl;
    cout << "nums'capacity:" << nums.capacity() << endl;
    nums.push_back(7);
    cout << "nums'size:" << nums.size() << endl;
    cout << "nums'capacity:" << nums.capacity() << endl;
    nums.push_back(8);
    cout << "nums'size:" << nums.size() << endl;
    cout << "nums'capacity:" << nums.capacity() << endl;

    cout << endl;
    cout << sizeof(nums) << endl;
}

void test2(){
    vector<int> nums{1,2,3,4,5};
    cout << "nums'size:" << nums.size() << endl;
    cout << "nums'capacity:" << nums.capacity() << endl;

    nums.pop_back();
    for(auto & num : nums){
        cout << num << " ";
    }
    cout << endl;
    
    nums.pop_back();
    nums.shrink_to_fit();
    cout << "nums'size:" << nums.size() << endl;
    cout << "nums'capacity:" << nums.capacity() << endl;
    
    nums.clear();
    cout << "nums'size:" << nums.size() << endl;
    cout << "nums'capacity:" << nums.capacity() << endl;

    cout << endl;
    //reserve可以与无参构造一起使用
    //如果确定了大概需要存放多少个元素
    //可以使用reserve去申请空间，但是不会存放元素
    //对比有参的构造，能够节省开销
    vector<int> nums2;
    nums2.reserve(10);
    cout << "nums2'size:" << nums2.size() << endl;
    cout << "nums2'capacity:" << nums2.capacity() << endl;
    for(auto & num : nums2){
        cout << num << " ";
    }
    cout << endl;
}

int main(void)
{
    test2();
    return 0;
}

