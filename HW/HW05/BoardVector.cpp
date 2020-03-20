#include "BoardVector.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;
namespace Board {
    BoardVector::BoardVector():AbstractBoard(),location_x(0),location_y(0){
        vector<int> temp;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                temp.push_back(-1);
            }
            vectorBoard.push_back(temp);
            temp.empty();
        }
        numberOfBoard++;
    }
    BoardVector::BoardVector(int size1,int size2):AbstractBoard(size1,size2),location_x(0),location_y(0){
        vector<int> temp;
        for(int i=0;i<size1;i++){
            for(int j=0;j<size2;j++){
                temp.push_back(-1);
            }
            vectorBoard.push_back(temp);
            temp.empty();
        }
        numberOfBoard++;
    }
    BoardVector::BoardVector(const BoardVector &obje):AbstractBoard(obje){
        for(int i=0;i<height;i++)
            for(int j=0;j<width;j++)
                vectorBoard[i][j] = obje(i,j);
        location_x = obje.getLocation_x();
        location_y = obje.getLocation_y();
    }
    int BoardVector::getLocation_y()const{
        return location_y;
    }
    int BoardVector::getLocation_x()const{
        return location_x;
    }
    void BoardVector::print()const{
        for(int i=0;i<height;i++){
            for(int j=0;j<width;j++){
                if(vectorBoard[i][j] == -1)
                    cout << "bb ";
                else{
                    if((vectorBoard[i][j] >= 0) && (vectorBoard[i][j] <= 9))
                        cout << "0" << vectorBoard[i][j] << " ";
                    else
                        cout << vectorBoard[i][j] << " ";
                }
                if((j % width) == (width - 1))
                    cout << endl;
            }
        }
    }
    void BoardVector::convertToArray(int arr[]){
        int temp, k = 0;
        for(int i=0;i<height;i++){
            for(int j=0;j<width;j++){
                temp = vectorBoard[i][j];
                arr[k] = temp;
                k++;
            }
        }
    }
    void BoardVector::convertToVector(int arr[]){
        int k = 0;
        for(int i=0;i<height;i++){
            vector<int> temp;
            for(int j=0;j<width;j++){
                temp.push_back(arr[k]);
                k++;
            }
            for(int j=0;j<width;j++)
                vectorBoard[i][j] = temp[j];
            temp.empty();
        }
    }
    int BoardVector::rightControl()const{
        int control = 0;
        if(location_y == width - 1)
            control = 0;
        else{
            if(vectorBoard[location_x][location_y+1] == 0)
                control = 0;
            else
                control = 1;
        }
        return control;
    }
    int BoardVector::leftControl()const{
        int control = 0;
        if(location_y == 0)
            control = 0;
        else{
            if(vectorBoard[location_x][location_y-1] == 0)
                control = 0;
            else
                control = 1;
        }
        return control;
    }
    int BoardVector::upControl()const{
        int control = 0;
        if(location_x == 0)
            control = 0;
        else{
            if(vectorBoard[location_x-1][location_y] == 0)
                control = 0;
            else
                control = 1;
        }
        return control;
    }
    int BoardVector::downControl()const{
        int control = 0;
        if(location_x == width - 1)
            control = 0;
        else{
            if(vectorBoard[location_x+1][location_y] == 0)
                control = 0;
            else
                control = 1;
        }
        return control;
    }
    void BoardVector::move(char choice){
        if(choice == 'R' || choice == 'r'){
            if(rightControl() == 1){
                vectorBoard[location_x][location_y] = vectorBoard[location_x][location_y+1];
                vectorBoard[location_x][location_y+1] = -1;
                numberOfMove++;
                lastMove = 'R';
                cout << "Right move: " << endl;
            }
            else
                cout << "YOU CANNOT THIS MOVE!" << endl;
        }
        else if(choice == 'L' || choice == 'l'){
            if(leftControl() == 1){
                vectorBoard[location_x][location_y] = vectorBoard[location_x][location_y-1];
                vectorBoard[location_x][location_y-1] = -1;                numberOfMove++;
                lastMove = 'L';
                cout << "Left move: " << endl;
            }
            else
                cout << "YOU CANNOT THIS MOVE!" << endl;
        }
        else if(choice == 'U' || choice == 'u'){
            if(upControl() == 1){
                vectorBoard[location_x][location_y] = vectorBoard[location_x-1][location_y];
                vectorBoard[location_x-1][location_y] = -1;
                numberOfMove++;
                lastMove = 'U';
                cout << "Up move: " << endl;
            }
            else
                cout << "YOU CANNOT THIS MOVE!" << endl;
        }
        else if(choice == 'D' || choice == 'd'){
            if(downControl() == 1){
                vectorBoard[location_x][location_y] = vectorBoard[location_x+1][location_y];
                vectorBoard[location_x+1][location_y] = -1;
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
    void BoardVector::findLocation(){
        for(int x=0;x<height;x++){
            for(int y=0;y<width;y++){
                if(vectorBoard[x][y] == -1){
                    location_x = x;
                    location_y = y;
                }
            }
        }
    }
    void BoardVector::boardFill(){
        int i;
        int randomNumber;
        int *board = new int[height*width];
        vector<int> temp;
        for(int i=0;i<height;i++){
            for(int j=0;j<width;j++){
                temp.push_back(-1);
            }
            vectorBoard.push_back(temp);
            temp.empty();
        }
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
        convertToVector(board);
        findLocation();
    }
    void BoardVector::writeToFile(string name){
        int i;
        ofstream myFile;
        myFile.open(name);
        int *board = new int[height*width];
        convertToArray(board);
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
    int BoardVector::convertStringToArray(char arr[], int game[], int size, int &numLoc){
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
    void BoardVector::readFromFile(string answer){
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
        convertToVector(game);
        findLocation();
    }
    void BoardVector::reset(){
        int *board = new int[height*width];
        convertToArray(board);
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
        convertToVector(board);
        findLocation();
    }
    int BoardVector::operator()(int x, int y)const{
        return vectorBoard[x][y];
    }
    bool BoardVector::operator==(const AbstractBoard &objeBoard){
        bool control = false;
        if((height == objeBoard.getHeight()) && (width == objeBoard.getWidth())){
            for(int i=0;i<height;i++){
                for(int j=0;j<width;j++){
                    if(objeBoard(i,j) == vectorBoard[i][j])
                        control = true;
                    else
                        control = false;
                }
            }
        }
        return control;
    }
    bool BoardVector::isSolved(){
        bool control = false;
        int *arr;
        arr = new int(height*width);
        convertToArray(arr);
        
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
        convertToArray(tempBoard);
        for(int i=0;i<height*width;i++){
            if(tempBoard[i] == arr[i])
                control = true;
            else
                control = false;
        }
        return control;
    }
    BoardVector& BoardVector::operator=(const BoardVector &obje){
        height = obje.getHeight();
        width = obje.getWidth();
        numberOfMove = obje.getNumberOfMoves();
        lastMove = obje.getLastMove();
        numberOfBoard = obje.getnumberOfBoards();
        for(int i=0;i<height;i++)
            for(int j=0;j<width;j++)
                vectorBoard[i][j] = obje(i,j);
        location_x = obje.getLocation_x();
        location_y = obje.getLocation_y();
        return *this;
    }
    BoardVector::~BoardVector(){
        for(int i=0;i<height;i++){
            vectorBoard[i].empty();
        }
        vectorBoard.empty();
    }
}
