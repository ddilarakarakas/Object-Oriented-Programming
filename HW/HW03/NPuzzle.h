#ifndef NPuzzle_h
#define NPuzzle_h
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "Board.h"
using namespace std;

class NPuzzle{
public:
    void startSet();
    void set();
    void print()const;
    void printReport();
    void readFromFile(string);
    void writeToFile(string);
    void shuffle();
    void reset();
    void setSize(int,int);
    void moveRandom();
    void moveIntelligent();
    void move(char);
    void solvePuzzle();
    void printAction()const;
    void boardFill();
    int control();
    int fileControl();
private:
    Board playGround;
    int height;
    int width;
    int gameBoard[81];
    int location;
    int moveCount;
};


#endif /* NPuzzle_h */
