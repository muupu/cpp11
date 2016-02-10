#include <iostream>
using namespace std;

class Base {
public:
	static void statemen()
	{
		cout << "Base statemen" << endl;
	}
};

class Derived : public Base {
public:
	void f( const Derived&);
	static void statemen()  // 添加了这个(不管有没有static)，Derived::statemen()都会输出：Derived statemen
	{
		cout << "Derived statemen" << endl;
	}
};

void Derived::f(const Derived &derived_obj)
{
	Base::statemen(); // 使用基类访问基类的静态成员
	Derived::statemen(); // 使用派生类访问基类的静态成员
	derived_obj.statemen(); // 派生类对象访问基类的静态成员
	statemen();       // this指针访问
}

int main()
{
	Derived d;
	d.f(d);
	return 0;
}