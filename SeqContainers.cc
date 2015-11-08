#include <list>
#include <string>
#include <deque>
#include <forward_list>
#include <array>

using namespace std;

int main()
{
	list<string> authors = {"Milton", "Shakespeare", "Austen"};
	vector<const char*> articles = {"a", "an", "the"};

	// 将一个容器(list2)初始化为另一个容器(authors)的拷贝
	// 两个容器的容器类型和元素类型都要相同！
	list<string> list2(authors);     // 类型匹配
	deque<string> authList(authors); // 错误：容器类型不匹配
	vector<string> words(articles);  // 错误：容器类型必须匹配
    // 正确：可以将const char*元素转换为string
	forward_list<string> words(articles.begin(), articles.end());

	auto it1 = authors.begin(); 
	auto it2 = authors.rbegin();  // 返回反向迭代器
	auto it3 = authors.cbegin();  // 返回const迭代器
	auto it4 = authors.crbegin(); 

	// 与顺序容器大小相关的构造函数
	vector<int> ivec(10, -1);     // 10个-1
	list<string> svec(10, "hi!")  // 10个string
	forward_list<int> ivec2(10);  // 10个0
	deque<string> svec2(10);      // 10个空string

	// 当定义标准库array，要指定容器的大小
	array<int, 42> a1;
	array<string, 10> a2;
	// 为了使用array类型，还要同时指定元素类型
	array<int ,10>::size_type i;  // 正确
	arrar<int>::size_type j;      // 错误：没有指定大小



	return 0;
}
