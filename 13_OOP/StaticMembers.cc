#include <iostream>
using namespace std;

class Base {
public:
	static void statemen();
	{
		cout << "Base statemen" << endl;
	}
};

class Derived : public Base {
	void f( const Derived&);
};

void Derived::f(const Derived &derived_obj)
{
	Base::statemen(); // 使用基类访问基类的静态成员
}

int main()
{
	Derived d;
	d.f(d);
	return 0;
}