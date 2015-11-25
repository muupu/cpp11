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
	// 计算满足size >= sz的元素的数目
	auto count = words.end() - wc;
	cout << count << " " << make_plural(count, "word", "s")
	     << " of length " << sz << " or longer" << endl;
	// 打印长度大于等于给定值的单词，每个单词后面接一个空格
	// for_each接受一个可调用对象，并对输入序列中的每个元素调用此对象
	for_each(wc, words.end(),
		     [](const string &s) { cout << s << " ";});
	cout << endl;
}

void fcn1()
{
	size_t v1 = 42;
	// 将v1拷贝到名为f的可调用对象
	auto f = [v1] { return v1; };
	v1 = 0;
	auto j = f(); // j为42；f保存了我们创建它时v1的拷贝
}

void fcn2()
{
	size_t v1 = 42;
	auto f2 = [&v1] { return v1; };
	v1 = 0;
	auto j = f2();
}

void fcn3()
{
	size_t v1 = 42;
	auto f = [v1] () mutable { return ++v1; };
	v1 = 0;
	auto j = f();
}

void fcn4()
{
	size_t v1 = 42;
	// 引用捕获的变量的修改
	auto f2 = [&v1] { return ++v1; };
	v1 = 0;
	auto j = f2();
}

bool check_size(const string &s, string::size_type sz)
{
	return s.size() >= sz;
}

void bind()
{
	auto check6 = bind(check_size, _1, 6);
	string s = "hello";
	bool b1 = check6(s);
	// auto wc = find_if(words.begin(), words.end(),
	// 	              [sz](const string &a))
	auto wc = find_if(words.begin(), words.end(), 
		              bind(check_size, _1, sz));

	auto g = bind(f, a, b, _2, c, _1);

}

void biggies(vector<string> &words,
	         vector<string>::size_type sz,
	         ostream &os = cout, char c = ' ')
{
	for_each(words.begin(), words.end(), [$os, c](const string &s) { os << s << c; });
	// os隐式捕获
	for_each(words.begin(), words.end(),
		     [&, c](const string &s) { os << s << c; });
	for_each(words.begin(), words.end(),
		     [=, &os](const string &s) { os << s << c; });
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