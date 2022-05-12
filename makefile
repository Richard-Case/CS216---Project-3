all: Project3

Project3: main.o Graph.o
	g++ -o Project3 main.o Graph.o

main.o: main.cpp Strings.h
	g++ -c main.cpp

Graph.o: Graph.cpp Graph.h Strings.h
	g++ -c Graph.cpp