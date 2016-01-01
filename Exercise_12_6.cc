#include <iostream>
#include <vector>

using namespace std;

vector<int>* new_vector()
{
	vector<int>* v = new vector<int>();
	return v;
}

vector<int>* input_vector(vector<int> * v)
{
	int value;
	while (cin >> value)
		v->push_back(value);
	return v;
}

void print_vector(vector<int> *v)
{
	for (const auto &value : *v)
		cout << value << " ";
	cout << endl;
}


int main()
{
	vector<int> *v = new_vector();
	auto v1 = input_vector(v);
	print_vector(v);

	delete v;
	v = nullptr;
	return 0;
}
