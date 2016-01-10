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
}