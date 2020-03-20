#ifndef BoardArray2D_h
#define BoardArray2D_h
#include "AbstractBoard.h"
#include <iostream>
using namespace std;

namespace Board{
    class BoardArray2D : public AbstractBoard{
    public:
        BoardArray2D();
        BoardArray2D(int,int);
        BoardArray2D(const BoardArray2D&);
        int getLocation_x()const;
        int getLocation_y()const;
        void print()const override;
        void readFromFile(string)override;
        void writeToFile(string)override;
        void move(char)override;
        void reset()override;
        int operator()(int,int)const override;
        bool operator==(const AbstractBoard&)override;
        BoardArray2D& operator=(const BoardArray2D&);
        bool isSolved() override;
        int rightControl()const;
        int leftControl()const;
        int upControl()const;
        int downControl()const;
        void findLocation();
        void convertToArray1D(int []);
        void convertToArray2D(int []);
        void convertToTempArray2D(int [],int **);
        void boardFill();
        int convertStringToArray(char [],int game[],int,int &);
        ~BoardArray2D();
    private:
        int **gameBoard;
        int location_x;
        int location_y;
    };
}

#endif /* BoardArray2D_h */
