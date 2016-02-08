#include <fstream>
#include <string>
#include <iostream>

using namespace std;

void runQueries(ifstream &infile)
{
	TextQuery tq(infile);
	string word;
	while(cin >> word && word != "q")
	{
		//cout << tq.query(word) << endl;
		print(cout, tq.query(s)) << endl;
	}
}

int main()
{
	ifstream file("text.txt");
	runQueries(file);
	file.close();
}