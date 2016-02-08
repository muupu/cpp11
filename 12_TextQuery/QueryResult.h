#ifndef QUERYRESULT_H_
#define QUERYRESULT_H_

#include <string>
#include <memory>
#include <vector>
#include <set>
#include <ostream>

using namespace std;

class QueryResult
{
friend std::ostream& print(std::ostream&, const QueryResult&);

public:
	using line_no = vector<string>::size_type;
	QueryResult(string s, 
		        shared_ptr<set<int>> p,
		        shared_ptr<vector<string>> f): sought(s), lines(p), file(f) { };
	~QueryResult();

private:
	string sought;
	shared_ptr<set<int>> lines;
	shared_ptr<vector<string>> file;
	/* data */
};

// 在给定的流上打印给定的QueryResult对象
ostream &print(ostream & os, const QueryResult &qr)
{
	os << qr.sought << " occurs " << qr.lines->size() << " times" << endl;
	  // << make_plural(qr.lines->size(), "time", "s") << endl;
	for (auto num : *qr.lines)
	{
		os << "/t(line " << num + 1 << ") "
		   << *(qr.file->begin() + num) << endl;

	}
	return os;
}

#endif