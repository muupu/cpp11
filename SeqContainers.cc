#include <list>
#include <string>
#include <deque>
#include <forward_list>
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

	return 0;
}
