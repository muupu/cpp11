

class Account {
public:
	void calculate() { amount += amount * interestRate; }

	// 静态成员函数不能声明为const。因为不包含this指针
	static double rate() { return interestRate; }
	static void rate(double);

private:
	std::string owner;
	double amount;

	static double interestRate;
	static double initRate();
};

// 当在类的外部定义静态成员，不能重复static关键字
void Account::rate(double newRate)
{
	interestRate = newRate;
}

// 必须在类的外部定义和初始化每个静态成员
// 只能定义一次
// 类似全局变量，一旦被定义，就将一直存在于程序的整个生命周期中
double Account::interestRate = initRate();