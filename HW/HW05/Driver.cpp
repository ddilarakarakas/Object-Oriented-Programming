#include "Driver.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

namespace Board {
    void Driver::testForBoardArray1D(){
        BoardArray1D obje_1D;
        BoardArray2D testObje2D;
        testObje2D.setSize(3,3);
        testObje2D.boardFill();
        obje_1D.setSize(3, 3);
        obje_1D.boardFill();
        obje_1D.print();
        obje_1D.move('l');
        obje_1D.print();
        obje_1D.move('r');
        obje_1D.print();
        obje_1D.move('r');
        obje_1D.print();
        obje_1D.move('u');
        obje_1D.print();
        obje_1D.move('l');
        obje_1D.print();
        obje_1D.move('d');
        obje_1D.print();
        string name;
        cout << "Write To File name(forexample.txt) : " ;
        cin >> name;
        obje_1D.writeToFile(name);
        cout << "Moves Number: " << obje_1D.getNumberOfMoves() << endl;
        cout << "Last Move: " << obje_1D.getLastMove() << endl;
        cout << "Reset : " << endl;
        obje_1D.reset();
        obje_1D.print();
        string name1;
        cout << "Read From File name(forexample.txt) : " ;
        cin >> name1;
        obje_1D.readFromFile(name1);
        cout << "File Board: " << endl;
        obje_1D.print();
        cout << "3. member : " << obje_1D(3,1) << endl;
        obje_1D.move('r');
        obje_1D.print();
        cout << "Are two boards equal?\nFirst board: " << endl;
        testObje2D.print();
        cout << "Second Board: " << endl;
        obje_1D.print();
        cout << "Answer: ";
        if(obje_1D == testObje2D)
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;
    }
    void Driver::testForBoardArray2D(){
        BoardArray2D obje_2D;
        BoardVector testObjeVector;
        testObjeVector.setSize(3,3);
        testObjeVector.boardFill();
        obje_2D.setSize(3, 3);
        obje_2D.boardFill();
        obje_2D.print();
        obje_2D.move('l');
        obje_2D.print();
        obje_2D.move('r');
        obje_2D.print();
        obje_2D.move('r');
        obje_2D.print();
        obje_2D.move('u');
        obje_2D.print();
        obje_2D.move('l');
        obje_2D.print();
        obje_2D.move('d');
        obje_2D.print();
        string name;
        cout << "Write To File name(forexample.txt) : " ;
        cin >> name;
        obje_2D.writeToFile(name);
        cout << "Moves Number: " << obje_2D.getNumberOfMoves() << endl;
        cout << "Last Move: " << obje_2D.getLastMove() << endl;
        cout << "Reset : " << endl;
        obje_2D.reset();
        obje_2D.print();
        string name1;
        cout << "Read From File name(forexample.txt) : " ;
        cin >> name1;
        obje_2D.readFromFile(name1);
        cout << "File Board: " << endl;
        obje_2D.print();
        cout << "3. member : " << obje_2D(0,2) << " " << endl;
        obje_2D.move('r');
        obje_2D.print();
        cout << "Are two boards equal?\nFirst board: " << endl;
        testObjeVector.print();
        cout << "Second Board: " << endl;
        obje_2D.print();
        cout << "Answer: ";
        if(obje_2D == testObjeVector)
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;
    }
    void Driver::testForBoardVector(){
        BoardVector objeVector;
        BoardArray1D testObje1D;
        testObje1D.setSize(3,3);
        testObje1D.boardFill();
        objeVector.setSize(3, 3);
        objeVector.boardFill();
        objeVector.print();
        objeVector.move('l');
        objeVector.print();
        objeVector.move('r');
        objeVector.print();
        objeVector.move('r');
        objeVector.print();
        objeVector.move('u');
        objeVector.print();
        objeVector.move('l');
        objeVector.print();
        objeVector.move('d');
        objeVector.print();string name;
        cout << "Write To File name(forexample.txt) : " ;
        cin >> name;
        objeVector.writeToFile(name);
        cout << "Moves Number: " << objeVector.getNumberOfMoves() << endl;
        cout << "Last Move: " << objeVector.getLastMove() << endl;
        cout << "Reset : " << endl;
        objeVector.reset();
        objeVector.print();
        string name1;
        cout << "Read From File name(forexample.txt) : " ;
        cin >> name1;
        objeVector.readFromFile(name1);
        cout << "File Board: " << endl;
        objeVector.print();
        objeVector.move('u');
        objeVector.print();
        objeVector.move('u');
        objeVector.print();
        cout << "3. member : " << objeVector(0,2) << " " << endl;
        objeVector.move('r');
        objeVector.print();
        cout << "Are two boards equal?\nFirst board: " << endl;
        testObje1D.print();
        cout << "Second Board: " << endl;
        objeVector.print();
        cout << "Answer: ";
        if(objeVector == testObje1D)
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;
    }
    void Driver::testForGlobalFunction(){
        vector<AbstractBoard *> boards;
        BoardArray1D obje;
        cout << "Enter the name is test file (example.txt) : ";
        string name;
        cin >> name;
        obje.readFromFile(name);
        obje.print();
        obje.move('r');
        obje.print();
        boards.push_back(&obje);
        obje.move('d');
        obje.print();
        boards.push_back(&obje);
        if(movesForSolution(boards) == true)
        	cout << "TRUE" << endl;
        else
        	cout << "FALSE" << endl;
    }
}
