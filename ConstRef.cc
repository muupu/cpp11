
class ConstRef {
public:
	ConstRef(int ii);

private:
	int i;
	const int ci;  // 常量ci和引用ri必须被初始化，不能先定义再在构造函数中赋值
	int &ri;
};

ConstRef::ConstRef(int ii): i(ii), ci(ii), ri(i) { } //显示地初始化引用和常量