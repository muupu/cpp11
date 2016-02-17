#include <iostream>
using namespace std;

class Test
{
private:
    int &a;
public:
    Test(int &b) : a(b)
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
    cout <<"b="<<b<<endl;
    test.Modify(4);
    cout <<"b="<<b<<endl;
    return 0;
}