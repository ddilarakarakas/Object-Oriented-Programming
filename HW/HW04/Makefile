all: HW04

HW04 : NPuzzle.o main.o 
	g++ main.o NPuzzle.o -o exe

NPuzzle.o : NPuzzle.cpp
	g++ -c -std=c++11 -Wall NPuzzle.cpp

main.o : main.cpp
	g++ -c -std=c++11 -Wall main.cpp

clean:
	rm *.o exe