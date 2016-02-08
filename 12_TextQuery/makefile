
textquery: main.o TextQuery.o QueryResult.o
	g++ -o textquery main.o TextQuery.o QueryResult.o
main.o: main.cc TextQuery.h
	g++ -c main.cc
TextQuery.o:TextQuery.cc TextQuery.h QueryResult.h
	g++ -c TextQuery.cc
QueryResult.o: QueryResult.cc QueryResult.h
	g++ -c QueryResult.cc
clean:
	-rm -f textquery main.o TextQuery.o
