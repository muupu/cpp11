#include <string>
#include <memory>
#include "StrBlob.cc"


class StrBlobPtr {
public:
	StrBlobPtr(): curr(0) { }

	StrBlobPtr(StrBlob &a, size_t sz = 0): wptr(a.data), curr(sz) { }

	std::string& deref() const;

	StrBlobPtr& incr();
private:
	// 若检查成功，check返回一个指向vector的shared_ptr
	std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string&) const;

	// 保存一个weak_ptr，意味着底层vector可能会被销毁
	std::weak_ptr<std::vector<std::string>> wptr;

private:
	// 在数组中的位置
	std::size_t curr; 
}