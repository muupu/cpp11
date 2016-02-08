
textquery: main.o TextQuery.o
	g++ -o textquery main.o TextQuery.o
main.o: main.cc TextQuery.h
	g++ -c main.cc
TextQuery.o:TextQuery.cc TextQuery.h QueryResult.h
	g++ -c TextQuery.cc
clean:
	-rm -f textquery main.o TextQuery.o
