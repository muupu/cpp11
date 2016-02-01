#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

using namespace std;

/***  Sorting operations (on sorted ranges) ***/
bool mygreater(int i,int j) { return (i>j); }

// std::partial_sort

void test_partial_sort()
{
	std::array<int, 10> s{5, 7, 4, 2, 8, 6, 1, 9, 0, 3};
 
 	// using default comparison (operator <):
    std::partial_sort(s.begin(), s.begin() + 5, s.end());
    for (int a : s) {
        std::cout << a << " ";
    } 
    cout << endl;
    // using function as comp
  	std::partial_sort(s.begin(), s.begin() + 5, s.end(), mygreater);
  	for (int a : s) {
        std::cout << a << " ";
    }
    cout << endl;
}

// std::nth_element
// 对给定范围[first,last)内的元素进行重新布置.
// 方法是,nth位置的元素放置的值就是把所有元素排序后在nth位置的值.
// 把所有不大于nth的值放到nth的前面,把所有不小于nth的值放到nth后面.
void test_nth_element()
{
	// array
	int a[]={3,5,2,6,1,4};
	std::nth_element(a, a+3, a+sizeof(a)/sizeof(int));
	cout << "The fourth element is: " << a[3] << endl; 
	// output array a[]
  	copy(a, a+sizeof(a)/sizeof(int), ostream_iterator<int>(cout, " "));
  	cout << endl;

	// vector
	std::vector<int> v{5, 6, 4, 3, 2, 6, 7, 9, 3};
 
    std::nth_element(v.begin(), v.begin() + v.size()/2, v.end());
    std::cout << "The median is " << v[v.size()/2] << '\n';
 
    std::nth_element(v.begin(), v.begin()+1, v.end(), std::greater<int>());
    std::cout << "The second largest element is " << v[1] << '\n';
}

int main()
{

	/***  Sorting operations (on sorted ranges) ***/
	test_partial_sort();
    // test_nth_element();
}