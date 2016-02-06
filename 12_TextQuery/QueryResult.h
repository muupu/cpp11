#include <string>
#include <memory>
#include <vector>
#include <set>

using namespace std;

class QueryResult
{
friend std::ostream& print(std::ostream&, const QueryResult&);

public:
	QueryResult(string s, 
		        shared_ptr<set<line_no>> p,
		        shared_ptr<vector<string>> f): sought(s), lines(p), file(f) { };
	~QueryResult();

private:
	string sought;
	shared_ptr<set<line_no>> lines;
	shared_ptr<vector<string>> file;
	/* data */
};