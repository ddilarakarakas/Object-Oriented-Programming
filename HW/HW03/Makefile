all: HW03

HW03 : NPuzzle.o Board.o  main.o 
	g++ main.o NPuzzle.o Board.o -o exe

NPuzzle.o : NPuzzle.cpp
	g++ -c -std=c++11 -Wall NPuzzle.cpp
	
Board.o : Board.cpp
	g++ -c -std=c++11 -Wall Board.cpp

main.o : main.cpp
	g++ -c -std=c++11 -Wall main.cpp

clean:
	rm *.o exe


