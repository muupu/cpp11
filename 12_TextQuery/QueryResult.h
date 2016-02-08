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
	//using line_no = vector<string>::size_type;
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


#endif