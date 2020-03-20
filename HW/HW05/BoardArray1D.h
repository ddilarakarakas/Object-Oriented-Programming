#ifndef BoardArray1D_h
#define BoardArray1D_h
#include <iostream>
#include "AbstractBoard.h"
using namespace std;

namespace Board {
    class BoardArray1D : public AbstractBoard{
    public:
        BoardArray1D();
        BoardArray1D(int,int);
        BoardArray1D(const BoardArray1D &);
        int getLocation()const;
        void print()const override;
        void readFromFile(string)override;
        void writeToFile(string)override;
        void move(char)override;
        void reset()override;
        int operator()(int,int)const override;
        bool operator==(const AbstractBoard &)override;
        BoardArray1D& operator=(const BoardArray1D &);
        bool isSolved() override;
        int rightControl()const;
        int leftControl()const;
        int downControl()const;
        int upControl()const;
        int findLocation();
        void boardFill();
        int convertStringToArray(char [],int game[],int,int &);
        ~BoardArray1D();
    private:
        int *gameBoard;
        int location;
    };
}
#endif /* BoardArray1D_h */
