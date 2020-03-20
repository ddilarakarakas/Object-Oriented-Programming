#ifndef BoardVector_h
#define BoardVector_h
#include "AbstractBoard.h"
#include <iostream>
#include <vector>
using namespace std;

namespace Board{
    class BoardVector : public AbstractBoard{
    public:
        BoardVector();
        BoardVector(int,int);
        BoardVector(const BoardVector&);
        int getLocation_x()const;
        int getLocation_y()const;
        void print()const override;
        void readFromFile(string)override;
        void writeToFile(string)override;
        void move(char)override;
        void reset()override;
        int operator()(int,int)const override;
        bool operator==(const AbstractBoard&)override;
        bool isSolved()override;
        int rightControl()const;
        int leftControl()const;
        int upControl()const;
        int downControl()const;
        void findLocation();
        void convertToArray(int []);
        void convertToVector(int []);
        void boardFill();
        int convertStringToArray(char [],int game[],int,int &);
        BoardVector& operator=(const BoardVector&);
        ~BoardVector();
    private:
        vector<vector<int> > vectorBoard;
        int location_x;
        int location_y;
    };
}
#endif /* BoardVector_h */
