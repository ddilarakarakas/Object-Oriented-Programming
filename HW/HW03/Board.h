#ifndef Board_h
#define Board_h
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

class Board{
public:
    void set();
    int tempBoard[81];
    void fillTempBoard();
    void print()const;
    void readFromFile(string);
    void writeToFile(string);
    void reset();
    void setSize(int,int);
    void move(char);
    bool isSolved();
    int invCount();
    int findLocation();
    int numberMoves();
    int endGameControl();
    int upControl();
    int downControl();
    int leftControl();
    int rightControl();
    void shuffleBoard();
    int height();
    int width();
    void boardFill();
    int convert(char [],int,int &);
    void updateBoard(int []);
    void updateMove();
private:
    int size1;
    int size2;
    int board[81];
    int location;
    int numberOfMoves = 0;
};

#endif /* Board_h */
