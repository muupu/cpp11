#include <string>
#include <iostream>
#include <vector>

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
	cout << compare(1, 0) << endl;
	vector<int> vec1{1, 2, 3}, vec2{1, 2, 3}, vec3{4, 5, 6};
	cout << compare(vec1, vec2) << endl;
	cout << compare(vec1, vec3) << endl;
}

int main()
{
	template_example();

	return 0;
}