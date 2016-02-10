#include <string>

class Quote {
public:
	Quote() = default;
	Quote(const std::string &book, double sales_price):
		bookNo(book), price(sales_price) { }
	std::string isbn() const { return bookNo; }
	virtual double net_price(std::size_t n) const
		{ return n * price;}
	// 基类的析构函数通常都应该添加virtual声明
	virtual ~Quote() = default; // 对析构函数进行动态绑定

private:
	std::string bookNo;
protected:
	double price = 0.0;
};

class Bulk_quote : public Quote {
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string&, double, std::size_t, double);
	double net_price(std::size_t) const override; 

private:
	std::size_t min_qty = 0;
	double discount = 0.0;
};

Bulk_quote::Bulk_quote(const std::string& book, double p, std::size_t qty, double disc) :
	Quote(book, p), min_qty(qty), discount(disc) 
	{ }

double Bulk_quote::net_price(size_t cnt) const
{
	if (cnt >= min_qty)
		return cnt * (1 - discount) * price;
	else
		return cnt * price;
}


