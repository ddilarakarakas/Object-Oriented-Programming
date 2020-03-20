exe : header.o main.o 
	g++ -o exe main.o header.o

header.o : header.cpp
	g++ -c -std=c++11 -Wall header.cpp

main.o : main.cpp
	g++ -c -std=c++11 -Wall main.cpp

clean:
	rm *.o exe


