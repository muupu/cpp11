#include <iostream>

using namespace std;  

void Print(const char* str)   
{
    cout<<"holle "<<str<<endl;   
}

template<typename  Fun>
void CallBackFun(void(*Fun)(const char* str), const char* str)   
{   
    (*Fun)(str);   
}   

int main()   
{   
    CallBackFun(&Print, "world");
    return  0;
}   
