all: gg.o main.o
	g++ -Wall -o getallen gg.o main.o
gg.o: gg.cpp gg.h
	g++ -Wall -c gg.cpp
main.o: main.cpp gg.h
	g++ -Wall -c main.cpp
