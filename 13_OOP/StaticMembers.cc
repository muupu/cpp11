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
	void statemen()
	{
		cout << "Derived statemen" << endl;
	}
};

void Derived::f(const Derived &derived_obj)
{
	Base::statemen(); // 使用基类访问基类的静态成员
	Derived::statemen(); // 使用派生类访问基类的静态成员
}

int main()
{
	Derived d;
	d.f(d);
	return 0;
}