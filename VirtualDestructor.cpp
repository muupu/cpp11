#include<iostream>
#include<string>

using namespace std;

class A
{
public:

	A()
	{ }
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
