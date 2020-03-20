#include "BoardArray2D.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

namespace Board {
    BoardArray2D::BoardArray2D():AbstractBoard(),location_x(0),location_y(0){
        gameBoard = new int*[2];
        for(int i=0;i<2;i++)
            gameBoard[i] = new int[2];
        numberOfBoard++;
    }
    BoardArray2D::BoardArray2D(int size1,int size2):AbstractBoard(size1,size2),location_x(0),location_y(0){
        gameBoard = new int*[size1];
        for(int i=0;i<size1;i++)
            gameBoard[i] = new int[size2];
        for(int i=0;i<size1;i++)
            for(int j=0;j<size2;j++){
                gameBoard[i][j] = -1;
            }
        numberOfBoard++;
    }
    BoardArray2D::BoardArray2D(const BoardArray2D &obje):AbstractBoard(obje){
        for(int i=0;i<height;i++)
            for(int j=0;j<width;j++)
                gameBoard[i][j] = obje(i,j);
        location_x = obje.getLocation_x();
        location_y = obje.getLocation_y();
    }
    int BoardArray2D::getLocation_y()const{
        return location_y;
    }
    int BoardArray2D::getLocation_x()const{
        return location_x;
    }
    void BoardArray2D::print()const{
        for(int i=0;i<height;i++){
            for(int j=0;j<width;j++){
                if(gameBoard[i][j] == -1)
                    cout << "bb ";
                else{
                    if((gameBoard[i][j] >= 0) && (gameBoard[i][j] <= 9))
                        cout << "0" << gameBoard[i][j] << " ";
                    else
                        cout << gameBoard[i][j] << " ";
                }
                if((j % width) == (width - 1))
                    cout << endl;
            }
        }
    }
    int BoardArray2D::rightControl()const{
        int control = 0;
        if(location_y % width == width - 1)
            control = 0;
        else{
            if(gameBoard[location_x][location_y+1] == 0)
                control = 0;
            else
                control = 1;
        }
        return control;
    }
    int BoardArray2D::leftControl()const{
        int control = 0;
        if(location_y == 0)
            control = 0;
        else{
            if(gameBoard[location_x][location_y-1] == 0)
                control = 0;
            else
                control = 1;
        }
        return control;
    }
    int BoardArray2D::upControl()const{
        int control = 0;
        if(location_x % height == 0)
            control = 0;
        else{
            if(gameBoard[location_x-1][location_y] == 0)
                control = 0;
            else
                control = 1;
        }
        return control;
    }
    int BoardArray2D::downControl()const{
        int control = 0;
        if(location_x % width == width - 1)
            control = 0;
        else{
            if(gameBoard[location_x+1][location_y] == 0)
                control = 0;
            else
                control = 1;
        }
        return control;
    }
    void BoardArray2D::move(char choice){
        if(choice == 'R' || choice == 'r'){
            if(rightControl() == 1){
                gameBoard[location_x][location_y] = gameBoard[location_x][location_y+1];
                gameBoard[location_x][location_y+1] = -1;
                numberOfMove++;
                lastMove = 'R';
                cout << "Right move: " << endl;
            }
            else
                cout << "YOU CANNOT THIS MOVE!" << endl;
        }
        else if(choice == 'L' || choice == 'l'){
            if(leftControl() == 1){
                gameBoard[location_x][location_y] = gameBoard[location_x][location_y-1];
                gameBoard[location_x][location_y-1] = -1;                numberOfMove++;
                lastMove = 'L';
                cout << "Left move: " << endl;
            }
            else
                cout << "YOU CANNOT THIS MOVE!" << endl;
        }
        else if(choice == 'U' || choice == 'u'){
            if(upControl() == 1){
                gameBoard[location_x][location_y] = gameBoard[location_x-1][location_y];
                gameBoard[location_x-1][location_y] = -1;
                numberOfMove++;
                lastMove = 'U';
                cout << "Up move: " << endl;
            }
            else
                cout << "YOU CANNOT THIS MOVE!" << endl;
        }
        else if(choice == 'D' || choice == 'd'){
            if(downControl() == 1){
                gameBoard[location_x][location_y] = gameBoard[location_x+1][location_y];
                gameBoard[location_x+1][location_y] = -1;
                numberOfMove++;
                lastMove = 'D';
                cout << "Down move: " << endl;
            }
            else
                cout << "YOU CANNOT THIS MOVE!" << endl;
        }
        else
            cout << "WRONG CHOICE!" << endl;
        findLocation();
    }
    void BoardArray2D::findLocation(){
        for(int x=0;x<height;x++){
            for(int y=0;y<width;y++){
                if(gameBoard[x][y] == -1){
                    location_x = x;
                    location_y = y;
                }
            }
        }
    }
    void BoardArray2D::convertToArray1D(int arr[]){
        int i = 0;
        for(int x=0;x<height;x++){
            for(int y=0;y<width;y++){
                arr[i] = gameBoard[x][y];
                i++;
            }
        }
    }
    void BoardArray2D::convertToArray2D(int arr[]){
        int i = 0;
        for(int x=0;x<height;x++){
            for(int y=0;y<width;y++){
                gameBoard[x][y] = arr[i];
                i++;
            }
        }
    }
    void BoardArray2D::boardFill(){
        int i;
        int randomNumber;
        int *board = new int[height*width];
        gameBoard = new int*[height];
        for(int i=0;i<height;i++)
            gameBoard[i] = new int[width];
        for(i=0;i<height*width;i++)
            board[i] = -1;
        int control = 0;
        while(control == 0){
            for(i=1;i<height*width;i++){
                randomNumber = (rand()%(height*width));
                if(board[randomNumber] == -1)
                    board[randomNumber] = i;
                else
                    i--;
            }
            if(solved(board,height*width) == 1){
                control = 1;
            }
            else{
                for(i=0;i<height*width;i++)
                    board[i] = -1;
            }
        }
        convertToArray2D(board);
        findLocation();
    }
    void BoardArray2D::writeToFile(string name){
        int i;
        ofstream myFile;
        myFile.open(name);
        int *board = new int[height*width];
        convertToArray1D(board);
        for(i=0;i<height*width;i++){
            if(i % width == 0){
                if(board[i] == -1)
                    myFile << "bb";
                else{
                    if((board[i] >= 0) && (board[i] <= 9))
                        myFile << "0" << board[i];
                    else
                        myFile << board[i];
                }
            }
            else{
                if(board[i] == -1)
                    myFile << " bb";
                else{
                    if((board[i] >= 0) && (board[i] <= 9))
                        myFile << " " << "0" << board[i];
                    else
                        myFile << " " << board[i];
                }
            }
            if((i % width) == (width - 1))
                myFile << endl;
        }
    }
    int BoardArray2D::convertStringToArray(char arr[], int game[], int size, int &numLoc){
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
    void BoardArray2D::readFromFile(string answer){
        string line;
        int game[500];
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
        
        for(int i=0;i<height;i++)
            gameBoard[i] = nullptr;
        gameBoard = nullptr;
        int **tempBoard = new int*[height];
        for(int i=0;i<height;i++)
            tempBoard[i] = new int[width];
        convertToTempArray2D(game, tempBoard);
        gameBoard = tempBoard;
        findLocation();
        
        
        
        
    }
    void BoardArray2D::convertToTempArray2D(int arr[], int **tempArray){
        int i = 0;
        for(int x=0;x<height;x++){
            for(int y=0;y<width;y++){
                tempArray[x][y] = arr[i];
                i++;
            }
        }
    }
    void BoardArray2D::reset(){
        int *board = new int[height*width];
        convertToArray1D(board);
        int temp;
        for(int i=0;i<height*width;i++){
            for(int j=i+1;j<height*width;j++){   //Bubble short
                if(board[i] > board[j]){
                    temp = board[i];
                    board[i] = board[j];
                    board[j] = temp;
                }
            }
        }
        temp = board[0];
        for(int i=0;i<height*width;i++)
            board[i] = board[i+1];
        board[height*width-1] = temp;
        convertToArray2D(board);
        findLocation();
    }
    int BoardArray2D::operator()(int x, int y)const{
        return gameBoard[x][y];
    }
    bool BoardArray2D::operator==(const AbstractBoard &objeBoard){
        bool control = false;
        if((height == objeBoard.getHeight()) && (width == objeBoard.getWidth())){
            for(int i=0;i<height;i++){
                for(int j=0;j<width;j++){
                    if(objeBoard(i,j) == gameBoard[i][j])
                        control = true;
                    else
                        control = false;
                }
            }
        }
        return control;
    }
    bool BoardArray2D::isSolved(){
        bool control = false;
        int *arr;
        arr = new int(height*width);
        convertToArray1D(arr);
        
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
        
        int *tempBoard = new int[height*width];
        convertToArray1D(tempBoard);
        for(int i=0;i<height*width;i++){
            if(tempBoard[i] == arr[i])
                control = true;
            else
                control = false;
        }
        return control;
    }
    BoardArray2D& BoardArray2D::operator=(const BoardArray2D &obje){
        height = obje.getHeight();
        width = obje.getWidth();
        numberOfMove = obje.getNumberOfMoves();
        lastMove = obje.getLastMove();
        numberOfBoard = obje.getnumberOfBoards();
        for(int i=0;i<height;i++)
            for(int j=0;j<width;j++)
                gameBoard[i][j] = obje(i,j);
        location_x = obje.getLocation_x();
        location_y = obje.getLocation_y();
        return *this;
    }
    BoardArray2D::~BoardArray2D(){
        for(int i=0;i<height;i++)
            delete [] gameBoard[i];
        delete [] gameBoard;
    }
}
