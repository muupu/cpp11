

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
}