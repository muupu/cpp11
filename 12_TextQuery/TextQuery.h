#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <memory>
#include <sstream>
#include "QueryResult.h"

using namespace std;

class TextQuery
{
public:
	// using line_no = vector<string>::size_type;
	TextQuery(ifstream&);
	~TextQuery();
	QueryResult query(const string&) const;

private:
	shared_ptr<vector<string>> file;
	// 每个单词到它所在的行号的集合的映射
	map<string, shared_ptr<set<int>>> wm;
	
};

TextQuery::TextQuery(ifstream &is): file(new vector<string>)
{
	string text;
	while (getline(is, text))
	{
		file->push_back(text);
		int n = file->size() - 1; // 当前行号
		istringstream line(text); // 将行文本分解为单词
		string word;
		while (line >> word) {
			auto &lines = wm[word]; // lines是个shared_ptr指针的引用
			if (!lines)
				lines.reset(new set<int>); // reset: 分配一个新的set
			lines->insert(n);
		}
	}
}

QueryResult
TextQuery::query(const string &sought) const
{
	static shared_ptr<set<int>> nodata(new set<int>);
	auto loc = wm.find(sought);
	if (loc == wm.end())
	{
		return QueryResult(sought, nodata, file);
	}
	else
	{
		return QueryResult(sought, loc->second, file);
	}
}