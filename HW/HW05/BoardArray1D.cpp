#include "BoardArray1D.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

namespace Board {
    BoardArray1D::BoardArray1D():AbstractBoard(),location(0){
        gameBoard = new int;
        numberOfBoard++;
    }
    BoardArray1D::BoardArray1D(int size1,int size2):AbstractBoard(size1,size2),location(0){
        gameBoard = new int(size1*size2);
        for(int i=0;i<size1*size2;i++)
            gameBoard[i] = -1;
        numberOfBoard++;
    }
    BoardArray1D::BoardArray1D(const BoardArray1D &obje):AbstractBoard(obje){
        int k = 0;
        for(int i=0;i<height;i++){
            for(int j=0;j<width;j++){
                gameBoard[k] = obje(i,j);
                k++;
            }
        }
        location = obje.getLocation();
    }
    int BoardArray1D::getLocation()const{
        return location;
    }
    void BoardArray1D::print()const{
        int i;
        for(i=0;i<height*width;i++){
            if(gameBoard[i] == -1)
                cout << "bb ";
            else{
                if((gameBoard[i] >= 0) && (gameBoard[i] <= 9))
                    cout << "0" << gameBoard[i] << " ";
                else
                    cout << gameBoard[i] << " ";
            }
            if((i % width) == (width - 1))
                cout << endl;
        }
    }
    void BoardArray1D::writeToFile(string name){
        int i;
        ofstream myFile;
        myFile.open(name);
        for(i=0;i<height*width;i++){
            if(i % width == 0){
                if(gameBoard[i] == -1)
                    myFile << "bb";
                else{
                    if((gameBoard[i] >= 0) && (gameBoard[i] <= 9))
                        myFile << "0" << gameBoard[i];
                    else
                        myFile << gameBoard[i];
                }
            }
            else{
                if(gameBoard[i] == -1)
                    myFile << " bb";
                else{
                    if((gameBoard[i] >= 0) && (gameBoard[i] <= 9))
                        myFile << " " << "0" << gameBoard[i];
                    else
                        myFile << " " << gameBoard[i];
                }
            }
            if((i % width) == (width - 1))
                myFile << endl;
        }
    }
    int BoardArray1D::rightControl()const{
        int control = 0;
        if((location % width) == (width - 1))
            control = 0;
        else{
            if(gameBoard[location+1] == 0)
                control = 0;
            else
                control = 1;
        }
        return control;
    }
    int BoardArray1D::leftControl()const{
        int control = 0;
        if(location % width == 0)
            control = 0;
        else{
            if(gameBoard[location-1] == 0)
                control = 0;
            else
                control = 1;
        }
        return control;
    }
    int BoardArray1D::downControl()const{
        int control = 0;
        if(location >= height*width - width && location <= height*width - 1)
            control = 0;
        else{
            if(gameBoard[location+width] == 0)
                control = 0;
            else
                control = 1;
        }
        return control;
    }
    int BoardArray1D::upControl()const{
        int control = 0;
        if(location < width)
            control = 0;
        else{
            if(gameBoard[location-width] == 0)
                control = 0;
            else
                control = 1;
        }
        return control;
    }
    void BoardArray1D::move(char choice){
        if(choice == 'R' || choice == 'r'){
            if(rightControl() == 1){
                gameBoard[location] = gameBoard[location+1];
                gameBoard[location+1] = -1;
                numberOfMove++;
                lastMove = 'R';
                cout << "Right move: " << endl;
            }
            else
                cout << "YOU CANNOT THIS MOVE!" << endl;
        }
        else if(choice == 'L' || choice == 'l'){
            if(leftControl() == 1){
                gameBoard[location] = gameBoard[location-1];
                gameBoard[location-1] = -1;
                numberOfMove++;
                lastMove = 'L';
                cout << "Left move: " << endl;
            }
            else
                cout << "YOU CANNOT THIS MOVE!" << endl;
        }
        else if(choice == 'U' || choice == 'u'){
            if(upControl() == 1){
                gameBoard[location] = gameBoard[location-width];
                gameBoard[location-width] = -1;
                numberOfMove++;
                lastMove = 'U';
                cout << "Up move: " << endl;
            }
            else
                cout << "YOU CANNOT THIS MOVE!" << endl;
        }
        else if(choice == 'D' || choice == 'd'){
            if(downControl() == 1){
                gameBoard[location] = gameBoard[location+width];
                gameBoard[location+width] = -1;
                numberOfMove++;
                lastMove = 'D';
                cout << "Down move: " << endl;
            }
            else
                cout << "YOU CANNOT THIS MOVE!" << endl;
        }
        else
            cout << "WRONG CHOICE!" << endl;
        location = findLocation();
    }
    int BoardArray1D::findLocation(){
        for(int i=0;i<height*width;i++){
            if(gameBoard[i] == -1)
                location = i;
        }
        return location;
    }
    void BoardArray1D::boardFill(){
        int i;
        int randomNumber;
        for(i=0;i<height*width;i++)
            gameBoard[i] = -1;
        int control = 0;
        while(control == 0){
            for(i=1;i<height*width;i++){
                randomNumber = (rand()%(height*width));
                if(gameBoard[randomNumber] == -1)
                    gameBoard[randomNumber] = i;
                else
                    i--;
            }
            if(solved(gameBoard,height*width) == true){
                control = 1;
            }
            else{
                for(i=0;i<height*width;i++)
                    gameBoard[i] = -1;
            }
        }
    }
    void BoardArray1D::reset(){
        int temp;
        for(int i=0;i<height*width;i++){
            for(int j=i+1;j<height*width;j++){   //Bubble short
                if(gameBoard[i] > gameBoard[j]){
                    temp = gameBoard[i];
                    gameBoard[i] = gameBoard[j];
                    gameBoard[j] = temp;
                }
            }
        }
        temp = gameBoard[0];
        for(int i=0;i<height*width;i++)
            gameBoard[i] = gameBoard[i+1];
        gameBoard[height*width-1] = temp;
        location = findLocation();
    }
    int BoardArray1D::operator()(int x, int y)const{
        return gameBoard[x*y];
    }
    int BoardArray1D::convertStringToArray(char arr[], int game[], int size, int &numLoc){
        int size2 = 0;
        for(int i=0;i<size;i++){
            if(arr[i] <= '9' && arr[i] >= '0'){
                if(arr[i] == '0'){
                    if(arr[i+1] == '0'){
                        game[numLoc] = arr[i] - 48;
                        numLoc = numLoc + 1;
                        i++;
                    }
                    else{
                        game[numLoc] = arr[i+1] - 48;
                        numLoc = numLoc + 1;
                        i++;
                    }
                }
                else{
                    int num1 = arr[i] - 48;
                    int num2 = arr[i+1] - 48;
                    game[numLoc] = num1*10 + num2;
                    numLoc = numLoc + 1;
                    i++;
                }
            }
            if(arr[i] == 'b'){
                game[numLoc] = -1;
                numLoc = numLoc + 1;
                i++;
            }
            if(arr[i] == ' ')
                size2 = size2 + 1;
        }
        size2 = size2 + 1;
        return size2;
    }
    void BoardArray1D::readFromFile(string answer){
        string line;
        int *game = new int [500];
        char arr[500];
        height = 0;
        width = 0;
        fstream myfile(answer);
        int arrSize = 0, temp = 0;
        if(myfile.is_open()){
            while(getline(myfile,line )){
                height++;
                for(int i=0;i<38;i++){
                    if(line[i] == '\0')
                        break;
                    arr[i] = line[i];
                    arrSize++;
                }
                width = convertStringToArray(arr,game,arrSize,temp);
                arrSize = 0;
            }
            myfile.close();
        }
        else cout << "Unable to open file" << endl;
        gameBoard = nullptr;
        gameBoard = game;
        location = findLocation();
    }
    bool BoardArray1D::operator==(const AbstractBoard & objeBoard){
        int  k = 0;
        bool control = false;
        if((height == objeBoard.getHeight()) && (width == objeBoard.getWidth())){
            for(int i=0;i<height;i++){
                for(int j=0;j<width;j++){
                    if(objeBoard(i,j) == gameBoard[k])
                        control = true;
                    else
                        control = false;
                    k++;
                }
            }
        }
        return control;
    }
    bool BoardArray1D::isSolved(){
        bool control = false;
        int *arr;
        arr = new int(height*width);
        for(int i=0;i<height*width;i++){
            arr[i] = gameBoard[i];
        }
        
        int temp;
        for(int i=0;i<height*width;i++){
            for(int j=i+1;j<height*width;j++){   //Bubble short
                if(arr[i] > arr[j]){
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
        temp = arr[0];
        for(int i=0;i<height*width;i++)
            arr[i] = arr[i+1];
        arr[height*width-1] = temp;
        
        for(int i=0;i<height*width;i++){
            if(gameBoard[i] == arr[i])
                control = true;
            else
                control = false;
        }
        return control;
    }
    BoardArray1D& BoardArray1D::operator=(const BoardArray1D &obje){
        height = obje.getHeight();
        width = obje.getWidth();
        numberOfMove = obje.getNumberOfMoves();
        lastMove = obje.getLastMove();
        numberOfBoard = obje.getnumberOfBoards();
        int k = 0;
        for(int i=0;i<height;i++){
            for(int j=0;j<width;j++){
                gameBoard[k] = obje(i,j);
                k++;
            }
        }
        location = getLocation();
        return *this;
    }
    
    BoardArray1D::~BoardArray1D(){
        delete [] gameBoard;
    }
}
