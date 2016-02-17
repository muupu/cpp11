// 在C++中使用引用类型的成员变量

#include <iostream>
using namespace std;

class Test
{
private:
    int& a_;
    const int& b_;
public:
    Test(int& a, int& b) : a_(a), b_(b) // 引用类型的成员变量必须在构造函数的初始化列表中进行初始化
    {
    }
    void Modify(int value)
    {
        a_ = value;
        // b_ = value; // 不能修改const变量
    }
    void Print()
    {
        cout << "b_=" << b_ << endl;
    }

};
int main()
{
    int a = 3;
    int b = 5;
    Test test(a, b);
    cout <<"a=" << a << " b="<< b << endl;  // a=3
    test.Modify(4);
    test.Print();
    cout <<"a=" << a << " b="<< b << endl;  //  a=4
    return 0;
}