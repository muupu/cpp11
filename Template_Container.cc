#include <vector>
#include <list>
#include <iostream>

using namespace std;

template <typename T>
class Test
{
public:
    static bool func(const T &t)
	{
		cout << t << endl;
		return true;
	}
};

template <typename T, typename TAllocator, template <typename, typename> class TContainer>
class Test<TContainer<T, TAllocator>>
{
public:
	static bool func(const TContainer<T, TAllocator> &t)
	{
		// TContainer<T, TAllocator>::const_iterator iter;
		for (auto iter = t.begin(); iter != t.end(); ++iter)
		{
			cout << *iter << " ";
		}
		cout << endl;
		return true;
	}
};

int main()
{
	int a = 100;
	Test<int>::func(a);

	int array1[5] = {1, 2, 3, 4, 5};
	vector<int> v(array1, array1 + 5);
	Test<vector<int>>::func(v);

	double array2[3] = {2.4, 1.7, 5.5};
	list<double> l(array2, array2 + 3);
	Test<list<double>>::func(l);

	return 0;
}