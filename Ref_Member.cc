// 在C++中使用引用类型的成员变量

#include <iostream>
using namespace std;

class Test
{
private:
    int &a;
public:
    Test(int &b) : a(b) // 引用类型的成员变量必须在构造函数的初始化列表中进行初始化
    {
    }
    void Modify(int value)
    {
        a = value;
    }
};
int main()
{
    int b = 3;
    Test test(b);
    cout <<"b="<<b<<endl;  // b=3
    test.Modify(4);
    cout <<"b="<<b<<endl;  // b=4
    return 0;
}