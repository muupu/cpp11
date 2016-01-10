#include <cstring>
#include <iostream>

using namespace std;

char* strcat(char* str1, char* str2)
{

}

int main()
{
	const char *str1 = "abcd";
	const char *str2 = "efgh";
	char *newStr = new char[strlen(str1) + strlen(str2) + 1];
	strcpy(newStr, str1);
	strcat(newStr, str2);
	cout << "newStr:" << newStr << endl;

	string s1 = "abcd";
	string s2 = "efgh";
	strcpy(newStr, (s1 + s2).c_str());
	cout << "newStr:" << newStr << endl;
}