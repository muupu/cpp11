#include <string>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

template <typename T>
int compare(const T &v1, const T &v2)
{
	if (v1 < v2) return -1;
	if (v2 < v1) return 1;
	return 0;
}

int template_example()
{
	cout << "--- template_example ---" << endl;
	cout << compare(1, 0) << endl;
	vector<int> vec1{1, 2, 3}, vec2{1, 2, 3}, vec3{4, 5, 6};
	cout << compare(vec1, vec2) << endl;
	cout << compare(vec1, vec3) << endl;
}

// 非类型模板参数

template<unsigned N, unsigned M>
int compare(const char (&p1)[N], const char (&p2)[M])
{
	return strcmp(p1, p2);
}


int nontype_template_parameters_example()
{
	cout << "--- nontype_template_parameters_example ---" << endl;
	cout << compare("hi", "hi") << endl;
	cout << compare("hi", "hello") << endl;
}

int main()
{
	template_example();
	nontype_template_parameters_example();

	return 0;
}