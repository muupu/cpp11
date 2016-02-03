#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <memory>

using namespace std;

class QueryResult;
class TextQuery
{
public:
	using line_no = vector<string>::size_type;
	TextQuery(ifstream&);
	~TextQuery();
	QueryResult query(const string&) const;

private:
	shared_ptr<vector<string>> file;
	// 每个单词到它所在的行号的集合的映射
	map<string, shared_ptr<set<line_no>>> wm;
	
};

TextQuery::TextQuery(ifstream &is): file(new vector<string>)
{
	string text;
	while (getline(is, text))
	{
		file->push_back(text);
		int n = file->size() - 1;
		istringstream line(text);
		string word;
		while (line >> word) {
			auto &lines = wm[word];
			if (!lines)
				lines.reset(new set<line_no>);
			lines->insert(n);
		}
	}
}