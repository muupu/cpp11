#include <iostream>
using namespace std;

Sales_data::Sales_data(std::istream &is)
{
	read(is, *this); // 从is中读取一条交易信息然后存入this对象中
}

double Sales_data::avg_price() const
{
	if (units_sold)
		return revenue/units_sold;
	else
		return 0;
}

Sales_data& Sales_data::combine(const Sales_data &rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

istream &read(istream &is, Sales_data &item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

ostream &print(ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold << " "
	   << item.revenue << " " << item.avg_price();
	return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

int main()
{
	Sales_data total;
	if (read(cin, total))
	{
		Sales_data trans;
		while (read(cin, trans))
		{
			if (total.isbn() == trans.isbn())
			{
				total.combine(trans);
			}
			else 
			{
				print(cout, total) << endl;
				toal = trans;
			}
		}
		print(cout, total) << endl;
	}
	else
	{
		cerr << "No data?!" << endl;
	}

	// 隐式的类类型转换
	// 接受string的构造函数定义了从string类型向Sales_data隐式转换的规则（注意是由构造函数来定义这种规则）
	string null_book = "9-99-9999";
	// 编译器通过string类型的null_book构造一个临时的Sales_data对象
	// 该对象的units_sold和revenue等于0， bookNo等于null_book
	total.combine(null_book);  

	// 只允许一步类类型转换
	// total.combine("9-99-9999");  // 是错的，先转成string，再转成Sales_data

	// explicit构造函数只能用于直接初始化
	// Sales_data item = null_book; // 不能用于拷贝形式的初始化过程
	Sales_data item(null_book); // 只能像这样直接初始化
}