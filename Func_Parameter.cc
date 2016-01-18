#include <iostream>
using namespace std;  

void Print()   
{
    cout<<"hello world"<<endl;   
}

template<class T>
void CallBackFun(void(*T)())   
{   
    (*T)(); 
}   

int main()   
{
    CallBackFun(&Print);
    return  0;
}   
