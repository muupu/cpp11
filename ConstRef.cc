
class ConstRef {
public:
	ConstRef(int ii);

private:
	int i;
	const int ci;  // 常量ci和引用ri必须被初始化，不能先定义再在构造函数中赋值
	int &ri;
};

ConstRef::ConstRef(int ii): i(ii), ci(ii), ri(i) { } //显示地初始化引用和常量

class X {
	int i;
	int j;
public:
	// 成员的初始化顺序与它们在类中的定义顺序一致
	// 因此以下会先用未初始化的j来初始化i，再初始化j
	X(int val): j(val), i(j) { }
}