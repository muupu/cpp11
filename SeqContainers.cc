#include <list>
using namespace std;

int main()
{
	list<string> a = {"Milton", "Shakespeare", "Austen"};
	auto it1 = a.begin(); 
	auto it2 = a.rbegin();  // 返回反向迭代器
	auto it3 = a.cbegin();  // 返回const迭代器
	auto it4 = a.crbegin(); 

	return 0;
}
