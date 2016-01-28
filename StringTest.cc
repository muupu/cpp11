#include <iostream>
#include <string>

using namespace std;

void Test_Replace()
{
	string str="this is a test string.";
	string str2="n example";
	// Using positions
	str.replace(9,5,str2);          // "this is an example string." (1)
	std::cout << str << '\n';
}

int main()
{
	Test_Replace();
	return 0;
}