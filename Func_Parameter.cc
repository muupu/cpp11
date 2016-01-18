#include <iostream>
#include <functional>
using namespace std;

void Print(const char* str)   
{
    cout<<"hello "<<str<<endl;   
}

template<class _Fun>   
void CallBackFun(_Fun f,const char* str)   
{   
    f(str);   
}   

int main()   
{
    CallBackFun(Print, "world");
    return  0;
}   
