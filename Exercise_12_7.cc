#include <iostream>
#include <vector>
#include <memory>

using namespace std;

shared_ptr<vector<int>> new_shared_ptr()
{
	// shared_ptr<vector<int>> v; // 没有分配内存和初始化，后面push_back会出错
	auto v = make_share<vector<int>>();
	return v;
}

void input_vector(shared_ptr<vector<int>> v)
{
	int value;
	while (cin >> value)
		v->push_back(value);
}

void print_vector(shared_ptr<vector<int>> v)
{
	for (const auto &value : *v)
		cout << value << " ";
	cout << endl;
}

int main()
{
	auto v = new_shared_ptr();
	input_vector(v);
	print_vector(v);

	return 0;
}