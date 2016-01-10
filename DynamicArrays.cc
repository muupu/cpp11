#include <iostream>
#include <memory>
using namespace std;

void initializing_dynamic_arrays()
{
	int* p = new int[0]; // 动态分配空数组是合法的
}

void smart_pointers_and_dynamic_arrays()
{
	// 用unique_ptr管理动态数组，必须在对象类型后面跟一对空方括号
	unique_ptr<int[]> up(new int[10]);
	up.release(); // int[]说明up指向一个数组，当release时，会自动使用delete[]。

	// 如果希望使用shared_ptr管理一个动态数组，必须提供自己定义的删除器
	shared_ptr<int> sp(new int[10], [](int *p) { delete[] p; });
	sp.reset();
}

int main()
{
	initializing_dynamic_arrays();
	return 0;
}