#include <algorithm>
#include <numeric>
#include <iterator>

void readOnlyAlgorithm()
{
	// accumulate(第三个参数是和的初值)
	int sum = accumulate(vec.cbegin(), vec.cend(), 0);

	// accumulate蕴含的假设：序列中元素类型必须与第三个参数匹配（或者能够转换）
	// 初始时是空字符串
	string sum = accumulate(v.cbegin(), v.cend(), string(""));
	// 注意第三个参数显示地创建一个string。若直接传递一个字符串字面值是错误的
	// 因为const char*上没有定义+运算符
	// 错误：string num = accumulate(vec.cbegin(), vec.cend(), "");

	// equal（接受三个参数）
	// 第三个参数表示第二个序列的首元素
	equal(roster1.cbegin(), roster2.cend(), roster2.cbegin());
}

void writeAlgorithm()
{
	// fill
	fill(vec.begin(), vec.end(), 0); // 将每个元素重置为0
	fill(vec.begin(), vec.begin() + vec.size()/2, 10); // 子序列设置为10

	// 算法不检查写操作
	// fill_n：将给定值赋予迭代器指向的元素开始的指定个元素
	vector<int> vec;
	fill_n(vec.begin(), vec.size(), 0); // 正确：因为是空vector，所以vec.size()个数为0
	// fill_n(vec.begin(), 10, 0)       // 错误：修改vec（是个空vector）中不存在的元素

}

void backInserter()
{
	vector<int> vec; // 0个元素
	// back_inserter接受一个指向容器的引用，返回一个插入迭代器
	auto it = back_inserter(vec);
	// 通过插入迭代器赋值时，会调用push_back将一个具有给定值的元素添加的容器中
	*it = 42;

	vector<int> vec1;
	// fill_n将给定值(10)赋予迭代器指向的元素及其后的
	fill_n(back_inserter(vec1), 10, 0); // 正确：添加10个元素到vec1 --- 每次赋值都是调用push_back，而不是"="
	// fill_n(vec1.begin(), 10, 0)      // 错误：修改vec1（是个空vector）中不存在的元素
}

void copyAlgorithm()
{
	// 用copy实现内置数组的拷贝
	int a1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int a2[sizeof(a1)/sizeof(*a1)]; // a2与a1一样大小
	auto ret = copy(begin(a1), end(a1), a2);

}

void elimDups(vector<string> &words)
{
	sort(words.begin(), words.end());
	// unique返回一个指向不重复值范围末尾的迭代器
	auto end_unique = unique(words.begin(), words.end());
	// 使用vector的erase成员来完成真正的删除操作
	words.erase(end_unique, words.end());
}

int main()
{
	// find操作的是迭代器，因此find可以在任何容器中查找值
	// list<string> lst = ...
	string val = "a Value";
	auto result = find(lst.cbegin(), lst.cend(), val);

	// 用find在数组中查找值（指针就像内置数组的迭代器）
	int ia[] = {27, 210, 12, 47, 109, 83};
	int val2 = 83;
	// 使用标准库begin和end来获得指向ia的首元素和尾元素之后位置的指针
	int *result2 = find(begin(ia), end(ia), val);

	// 在序列的子范围查找
	auto result3 = find(ia + 1, ia + 4, val);
}