#include <list>
using namespace std;

int main()
{
	list<string> a = {"Milton", "Shakespeare", "Austen"};
	auto it1 = a.begin(); 
	auto it2 = a.rbegin(); 
	auto it3 = a.cbegin();
	auto it4 = a.crbegin();

	return 0;
}
