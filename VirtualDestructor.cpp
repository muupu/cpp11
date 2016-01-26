#include<iostream>
#include<string>

using namespace std;

class A
{
public:
	A()
	{ }
    virtual ~A()
    {cout<<"~A"<<endl; }
    
public:
	virtual int TestA() = 0;
};

class B : public A
{
public:
	B()
	{ }

	virtual ~B()
	{ cout<<"~B"<<endl; }

	virtual int TestA()
	{ return 100; }

};

int main()
{
	A *pA = new B();
	delete pA;
	cout<<"Finish"<<endl;
}




	//cout<<pA->testStr<<endl;
	//cout<<pA->TestA()<<endl;

//class C : public B
//{
//public:
//	virtual ~C()
//	{
//		cout<<"~C"<<endl;
//	}
//};
