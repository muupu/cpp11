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
	double net_price(std::size_t) const override;
};
