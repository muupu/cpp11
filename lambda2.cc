#include <iostream>     // std::cout
#include <algorithm>    // std::transform
#include <vector>       // std::vector
#include <functional>   // std::plus

int op_increase (int i) { return ++i; }

void printVec(std::vector<int> foo)
{
	for (auto it=foo.begin(); it!=foo.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}


// transform使用
void transform()
{
	std::vector<int> foo;
	std::vector<int> bar;

	// set some values:
	for (int i=1; i<6; i++)
		foo.push_back (i*10);                         // foo: 10 20 30 40 50

	bar.resize(foo.size());                         // allocate space

	std::transform (foo.begin(), foo.end(), bar.begin(), op_increase);
	                                              // bar: 11 21 31 41 51

	// std::plus adds together its two arguments:
	std::transform (foo.begin(), foo.end(), bar.begin(), foo.begin(), std::plus<int>());
	                                              // foo: 21 41 61 81 101

	std::cout << "foo contains:";
	printVec(foo);

	// Output:
    // foo contains: 21 41 61 81 101
}

// 指定lambda返回类型
void transform2()
{
	std::vector<int> v1;
	for (int i = -6; i < 6; i++)
	{
		v1.push_back(i);
	}

	
	// 使用transform将每个负数替换为正数
	std::transform(v1.begin(), v1.end(), v1.begin(), 
		           [] (int i) { return i < 0 ? -i : i;});

	// 默认情况下，如果一个lambda包含return之外的任何语句，则编译器假定返回void
	// 编译错误：编译器推断这个版本的lambda返回类型为void，但它返回了一个int值
	std::transform(v1.begin(), v1.end(), v1.begin(),
		            [](int i) { if (i < 0) return -i; else return i;});


	printVec(v1);

}

int main()
{
	transform();
	transform2();
	return 0;
}