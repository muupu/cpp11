#include <iostream>

using namespace std;  

void Print(const char* str)   
{
    cout<<"holle "<<str<<endl;   
}

template<typename  _Fun>
void CallBackFun(void(*_Fun)(const char*), const char* str)   
{   
    (*_Fun)(str);
}   

int main()   
{   
    CallBackFun(&Print, "world");
    return  0;
}   
