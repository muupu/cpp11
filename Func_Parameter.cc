#include <iostream>

using namespace std;  

typedef void (*Fun)(const char* str);

void Print(const char* str)   
{
    cout<<"holle "<<str<<endl;   
}

// template<typename  _Fun>
void CallBackFun(Fun f, const char* str)   
{   
    f(str);
}   

int main()   
{   
    CallBackFun(&Print, "world");
    return  0;
}   
