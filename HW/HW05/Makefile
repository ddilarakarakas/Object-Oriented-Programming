all: HW05

HW05 : AbstractBoard.o BoardArray1D.o BoardArray2D.o BoardVector.o Driver.o main.o 
	g++ main.o AbstractBoard.o BoardArray1D.o BoardArray2D.o BoardVector.o  Driver.o -o exe

AbstractBoard.o : AbstractBoard.cpp
	g++ -c -std=c++11 -Wall AbstractBoard.cpp

BoardArray1D.o : BoardArray1D.cpp
	g++ -c -std=c++11 -Wall BoardArray1D.cpp

BoardArray2D.o : BoardArray2D.cpp
	g++ -c -std=c++11 -Wall BoardArray2D.cpp

BoardVector.o : BoardVector.cpp
	g++ -c -std=c++11 -Wall BoardVector.cpp

Driver.o : Driver.cpp
	g++ -c -std=c++11 -Wall Driver.cpp

main.o : main.cpp
	g++ -c -std=c++11 -Wall main.cpp

clean:
	rm *.o exe