#include <iostream>
#include <string>

using namespace std;

void Test_Replace()
{
	string str="this is a test string.";
	string str2="n example";
	// Using positions
	str.replace(9,5,str2);          // "this is an example string." (1)
	cout << str << '\n';
	// Using iterators
	str.replace(str.begin(),str.begin()+6,"replace");  
	cout << str << '\n';            // "replaces an example string."
	str.replace(str.begin(),str.begin()+6,"");  
	cout << str << '\n';            // "es an example string."


}

int main()
{
	Test_Replace();
	return 0;
}