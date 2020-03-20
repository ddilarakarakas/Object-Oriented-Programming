#ifndef AbstractBoard_h
#define AbstractBoard_h
#include <iostream>
using namespace std;

namespace Board {
    class AbstractBoard{
    public:
        static int numberOfBoard;
        AbstractBoard();
        AbstractBoard(int,int);
        AbstractBoard(const AbstractBoard &);
        int getHeight()const;
        int getWidth()const;
        int getNumberOfMoves()const;
        int getnumberOfBoards()const;
        char getLastMove()const;
        void setSize(int,int);
        virtual void print()const = 0;
        virtual void readFromFile(string) = 0;
        virtual void writeToFile(string) = 0;
        virtual void move(char) = 0;
        virtual void reset() = 0;
        int invCount(int [],int);
        bool solved(int[],int);
        virtual bool isSolved() = 0;
        virtual int operator()(int,int)const = 0;
        virtual bool operator==(const AbstractBoard &) = 0;
        AbstractBoard& operator=(const AbstractBoard &);
        virtual ~AbstractBoard();
    protected:
        int height;
        int width;
        int numberOfMove;
        char lastMove;
    };
    bool movesForSolution(vector<AbstractBoard *>);
}

#endif /* AbstractBoard_h */
