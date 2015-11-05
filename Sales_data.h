#include <iostream>

class Sales_data
{
// 友元中可以访问该类中的非public成员
friend Sales_data add(const Sales_data&, const Sales_data&); 
friend std::ostream &print(std:ostream&, const Sales_data&);
friend std::istream &read(std::istream&, Sales_data& item); // read函数实现里面就可以使用item.units_sold

public:
	// 构造函数
	Sales_data() = default; // 默认构造函数
	Sales_data(const std::string &s) : bookNo(s) {}  // 构造函数初始值列表
	Sales_data(const std::string &s, unsigned n, double p):
	           bookNo(s), units_sold(n), revenue(p*n) {}
	Sales_data(std::istream &);

	std::string isbn() const {return bookNo;}
	Sales_data& combine(const Sales_data&);
	double avg_price() const;

private:
	std::string bookNo;      // 在默认构造函数中，默认初始化为空字符串
	unsigned units_sold = 0; // 由默认构造函数初始化
	double revenue = 0.0;
	/* data */
};

Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std:ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);