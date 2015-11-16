#include <string>
#include <algorithm>

using namespace std;

bool isShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}

int main()
{
	// sort接受一个二元谓词参数
	sort(words.begin(), words.end(), isSHorter);
	return 0;
}