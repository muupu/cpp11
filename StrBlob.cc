#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include <stdexcept>      // std::out_of_range

using namespace std;

// Blob类保存一组元素。与容器不同，Blob对象的不同拷贝之间共享相同的元素。
// 即，当我们拷贝一个Blob时，原Blob对象及其拷贝应该引用相同的底层对象。
class StrBlob {
public:
	typedef vector<string>::size_type size_type;
	StrBlob();
	StrBlob(initializer_list<string> il); // 接受一个初始化器的花括号列表
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }

	// 删除和添加元素
	void push_back(const string &t) { data->push_back(t); }
	void pop_back();

	// 元素访问
	string& front();
	string& back();

	long int use_count() { return data->use_count(); }
	void print();

private:
	shared_ptr<vector<string>> data;
	// 如果data[i]不合法，抛出一个异常
	void index_check(size_type i, const string &msg) const;
};

// 构造函数
// 默认构造函数分配一个空vector
StrBlob::StrBlob(): data(make_shared<vector<string>>()) { }
// 将花括号列表中的元素进行拷贝，来初始化vector的元素
StrBlob::StrBlob(initializer_list<string> il):
					data(make_shared<vector<string>>(il)) { }

// 检查给定索引i是否在合法范围；string传递给异常处理程序
void StrBlob::index_check(size_type i, const string &msg) const
{
	if (i >= data->size())
		throw out_of_range(msg);
}

// 删除元素
void StrBlob::pop_back()
{
	// 在试图访问元素之前必须检查vector为空
	index_check(0, "pop_back on empty StrBlob");
	data->pop_back();
}

// 访问元素
string& StrBlob::front()
{
	index_check(0, "front on empty StrBlob");
	return data->front();
}

string& StrBlob::back()
{
	index_check(0, "pop_back on empty StrBlob");
	return data->back();
}

void StrBlob::print()
{
	for (auto it = data.begin(); it < data.end(); it ++)
		cout << (*it) << '\n';  // 2
}

int main()
{
	StrBlob b1;
	{
		StrBlob b2 = {"a", "an", "the"};
		b1 = b2;
		b2.push_back("about");
		cout << "b2.use_count(): " << b2.use_count() << '\n';  // 2
	}
	cout << "b1.use_count(): " << b1.use_count() << '\n';  // 2
	b1.print();
	

	return 0;
}