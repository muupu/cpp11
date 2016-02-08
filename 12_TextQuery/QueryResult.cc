#include "QueryResult.h"

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
