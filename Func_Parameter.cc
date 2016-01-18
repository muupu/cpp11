#include <iostream>

using namespace std;  


class MyClass
{
public:
    void Print()   
    {
        cout<<"hello world"<<endl;   
    }
};

template<class T>
void CallBackFun(T* ptr,void(T::*MenFn)())   
{   
    (ptr->*MenFn)(); 
}   

int main()   
{
    MyClass cs;
    CallBackFun(&cs,&MyClass::Print);
    return  0;
}   
