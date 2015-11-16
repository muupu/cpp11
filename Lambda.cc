#include <string>
#include <algorithm>

using namespace std;

bool isShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
	eliDups(words);
	// 按长度排序，长度相同的单词维持字典序
	stable_sort(words.begin(), words.end(), 
		         [](const string &a, const string &b)
		         { return a.size() < b.size();});
	// 获取一个迭代器，指向第一个满足size()>=sz的元素
	auto wc = find_if(words.begin(), words.end(),
		[sz](const string &a)
			{ return a.size() >= sz; });
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