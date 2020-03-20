#ifndef NPuzzle_h
#define NPuzzle_h
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "NPuzzle.h"
using namespace std;

class NPuzzle{
public:
    NPuzzle();
    void print();
    void printReport();
    void readFromFile(string);
    void writeToFile(string);
    void shuffle();
    void reset();
    void setSize(int,int);
    void moveRandom();
    void move(char);
    void solvePuzzle();
    void printAction()const;
    void boardFill();
    int control();
    int fileControl();
    int getHeight()const;
    int getWidth()const;
    void ConvertToArray(int []);
    void ConvertToVector(int []);
    friend istream& operator >>(istream& inputStream,NPuzzle &game);
    friend ostream& operator <<(ostream& outputStream,NPuzzle &game);
private:
    class Board{
    public:
        Board();
        void print();
        void readFromFile(string);
        void writeToFile(string);
        void reset();
        void setSize(int,int);
        void move(char);
        bool isSolved();
        int invCount();
        int numberOfBoards()const;
        char lastMove()const;
        int numberOfMoves()const;
        void ConvertToArray(int []);
        void ConvertToVector(int []);
        int findLocation();
        int endGameControl();
        int upControl();
        int downControl();
        int leftControl();
        int rightControl();
        void boardFill();
        int convert(char [],int,int &);
        int getHeight()const;
        int getWidth()const;
        void shuffleBoard();
        void printReport();
        void moveRandom();
        int control();
        int fileControl();
        int operator ()(const Board&, int x,int y);
        bool operator ==(const Board &);
        bool controlBoard(Board, vector<Board> );
        bool solvePuzzle(vector<Board> ,int,int );
        bool endGameControl(Board);
    private:
        vector<vector<int> > vectorBoard;
        int fileBoard[1000];
        char moveLast;
        int moveCount;
        int numberBoard;
        int size1;
        int size2;
        int location;
    };
    vector<Board> boards;
    int numberBoards; // newly produced boards
};
#endif /* NPuzzle_h */
