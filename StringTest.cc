#include <iostream>
#include <string>
#include <functional> // bind2nd/equal_to
#include <algorithm> // remove_if

using namespace std;

// 将指定字符删除 
// bind2nd/remove_if/equal_to/string.erase
void removeAllChar()
{
	string tmp="asdfasf.asfdasdfsa.afssdfsda.asfdsdafa.";
	char c = '.';
	string::iterator new_end = remove_if(str.begin(), str.end(), bind2nd(equal_to<char>(),c));
    str.erase(new_end, str.end());
}


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
	// replace the first finded string
	// std::size_t found = str.find(str2);
	str.replace(str.find(str2),str2.length(),"");
	cout << str << '\n';            // "es a string."

}

int main()
{
	Test_Replace();
	return 0;
}