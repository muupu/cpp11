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
	sort(words.begin(), words.end(), isShorter);

	// stable_sort
	eliDups(words);
	stable_sort(words.begin(), words.end(), isShorter);
	for (const auto &s : words)
		cout << s << " ";
	cout << endl;

	return 0;
}