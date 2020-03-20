all: HW06

HW06 : GTUContainer.o GTUIterator.o GTUIteratorConst.o GTUSet.o GTUVector.o main.o 
	g++ main.o GTUContainer.o GTUIterator.o GTUIteratorConst.o GTUSet.o GTUVector.o -o exe

GTUContainer.o : GTUContainer.cpp
	g++ -c -std=c++11 -Wall GTUContainer.cpp

GTUIterator.o : GTUIterator.cpp
	g++ -c -std=c++11 -Wall GTUIterator.cpp

GTUIteratorConst.o : GTUIteratorConst.cpp
	g++ -c -std=c++11 -Wall GTUIteratorConst.cpp

GTUSet.o : GTUSet.cpp
	g++ -c -std=c++11 -Wall GTUSet.cpp

GTUVector.o : GTUVector.cpp
	g++ -c -std=c++11 -Wall GTUVector.cpp

main.o : main.cpp
	g++ -c -std=c++11 -Wall main.cpp

clean:
	rm *.o exe