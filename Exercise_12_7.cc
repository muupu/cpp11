#include <iostrem>
#include <vector>
#include <memory>

using namespace std;

shared_ptr<vector<int>> new_shared_ptr()
{
	shared_ptr<vector<int>> v;
	return v;
}

void input_vector(shared_ptr<vector<int>> v)
{
	int value;
	while (cin >> value)
		v->push_back(value)
}

void print_vector(shared_ptr<vector<int>> v)
{
	for (const auto &value : *v)
		cout << value << " "
	cout << endl;
}

int main()
{
	auto v = new_shared_ptr();
	input_vector(v);
	print_vector(v);

	return 0;
}