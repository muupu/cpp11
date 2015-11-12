#include <algorithm>
#include <numeric>

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