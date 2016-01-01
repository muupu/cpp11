#include <vector>
#include <string>
#include <memory>

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

private:
	shared_ptr<vector<string>> data;
	// 如果data[i]不合法，抛出一个异常
	void check(size_type i, const string &msg) const;
};

// 构造函数
// 默认构造函数分配一个空vector
StrBlob::StrBlob(): data(make_shared<vector<string>>()) { }
StrBlob::StrBlob(initializer_list<string> il):
					data(make_shared<vector<string>>(il)) { }

