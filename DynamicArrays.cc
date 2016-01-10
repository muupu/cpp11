#include <iostream>

using namespace std;

void initializing_dynamic_arrays()
{
	int* p = new int[0]; // 动态分配空数组是合法的
}

int main()
{
	initializing_dynamic_arrays();
	return 0;
}