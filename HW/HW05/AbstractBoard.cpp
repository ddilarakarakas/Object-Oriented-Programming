#include "AbstractBoard.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
using namespace std;

namespace Board{
    int AbstractBoard::numberOfBoard = 0;
    AbstractBoard::AbstractBoard():height(0),width(0),numberOfMove(0),lastMove('s'){
    }
    AbstractBoard::AbstractBoard(int size1,int size2):height(size1),width(size2),numberOfMove(0),lastMove('s'){
    }
    AbstractBoard::AbstractBoard(const AbstractBoard &obje):height(obje.getHeight()),width(obje.getWidth()),numberOfMove(obje.getNumberOfMoves()),lastMove(getLastMove()){
        numberOfBoard = obje.getnumberOfBoards();
    }
    int AbstractBoard::getHeight()const{
        return height;
    }
    int AbstractBoard::getWidth()const{
        return width;
    }
    int AbstractBoard::getNumberOfMoves()const{
        return numberOfMove;
    }
    int AbstractBoard::getnumberOfBoards()const{
        return numberOfBoard;
    }
    char AbstractBoard::getLastMove()const{
        return lastMove;
    }
    void AbstractBoard::setSize(int size1, int size2){
        height = size1;
        width = size2;
    }
    int AbstractBoard::invCount(int board[], int size){
        int count = 0;
        for (int i=0;i<size-1;i++)
            for (int j=i+1;j<size;j++)
                if(board[i]>board[j])
                    count++;
        return count;
    }
    bool AbstractBoard::solved(int board[], int size){
        int count = invCount(board,size);
        return (count % 2 == 0);
    }
    AbstractBoard& AbstractBoard::operator=(const AbstractBoard &obje){
        height = obje.getHeight();
        width = obje.getWidth();
        numberOfMove = obje.getNumberOfMoves();
        lastMove = obje.getLastMove();
        numberOfBoard = obje.getnumberOfBoards();
        return *this;
    }
    AbstractBoard::~AbstractBoard(){
        numberOfBoard--;
    }
    
    bool movesForSolution(vector<AbstractBoard *> boards){
        int numberBoard = boards[0]->getnumberOfBoards();
        bool control = true;
        AbstractBoard *temp = boards[numberBoard];
        temp->reset();
        for(int i=numberBoard;i>0;i--){
            if(temp == boards[i]){
                char move = '\0';
                if(boards[i-1]->getLastMove() == 'd')
                    move = 'u';
                if(boards[i-1]->getLastMove() == 'u')
                    move = 'd';
                if(boards[i-1]->getLastMove() == 'r')
                    move = 'l';
                if(boards[i-1]->getLastMove() == 'l')
                    move = 'r';
                if(boards[i-1]->getLastMove() == 's'){
                    control = false;
                    break;
                }
                temp->move(move);
            }
            else{
                control = false;
                break;
            }
        }
        return control;
    }
}




