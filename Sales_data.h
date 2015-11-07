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

	// 使用默认实参的构造函数
	Sales_data(std::string s = ""): bookNo(s) { }  
	Sales_data(std::string s, unsigned cnt, double rev):
	           bookNo(s), units_sold(cnt), revenue(rev*cnt) { }
	Sales_data(std::istream &is) { read(is, *this); }

	// 委托构造函数
	Sales_data():Sales_data("", 0, 0) { }
	Sales_data(std::string s):Sales_data(s, 0, 0) { }
	Sales_data(std::istream &is):Sales_data() { read(is, *this);}
	
public:
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