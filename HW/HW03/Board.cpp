#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "Board.h"
using namespace std;

void Board::set(){
    size1 = 0;
    size2 = 0;
    location = 0;
    numberOfMoves = 0;
    for(int i=0;i<81;i++)
        board[i] = -1;
}

void Board::fillTempBoard(){
    for(int i=0;i<81;i++)
        tempBoard[i] = board[i];
}

void Board::print()const{
    int i;
    for(i=0;i<size1*size2;i++){
        if(board[i] == -1)
            cout << "bb ";
        else{
            if((board[i] >= 0) && (board[i] <= 9))
                cout << "0" << board[i] << " ";
            else
                cout << board[i] << " ";
        }
        if((i % size2) == (size2 - 1))
            cout << endl;
    }
}

int Board::downControl(){
    int control = 0;
    if(location >= size1*size2 - size2 && location <= size1*size2 - 1)
        control = 0;
    else{
        if(board[location+size2] == 0)
            control = 0;
        else
            control = 1;
    }
    return control;
}

int Board::rightControl(){
    int control = 0;
    if((location % size2) == (size2 - 1))
        control = 0;
    else{
        if(board[location+1] == 0)
            control = 0;
        else
            control = 1;
    }
    return control;
}

int Board::leftControl(){
    int control = 0;
    if(location % size2 == 0)
        control = 0;
    else{
        if(board[location-1] == 0)
            control = 0;
        else
            control = 1;
    }
    return control;
}

int Board::upControl(){
    int control = 0;
    if(location < size2)
        control = 0;
    else{
        if(board[location-size2] == 0)
            control = 0;
        else
            control = 1;
    }
    return control;
}

void Board::move(char choice){
    if(choice == 'R' || choice == 'r'){
        if(rightControl() == 1){
            board[location] = board[location+1];
            board[location+1] = -1;
            numberOfMoves++;
        }
        else
            cout << "YOU CANNOT THIS MOVE!" << endl;
    }
    else if(choice == 'L' || choice == 'l'){
        if(leftControl() == 1){
            board[location] = board[location-1];
            board[location-1] = -1;
            numberOfMoves++;
        }
        else
            cout << "YOU CANNOT THIS MOVE!" << endl;
    }
    else if(choice == 'U' || choice == 'u'){
        if(upControl() == 1){
            board[location] = board[location-size2];
            board[location-size2] = -1;
            numberOfMoves++;
        }
        else
            cout << "YOU CANNOT THIS MOVE!" << endl;
    }
    else if(choice == 'D' || choice == 'd'){
        if(downControl() == 1){
            board[location] = board[location+size2];
            board[location+size2] = -1;
            numberOfMoves++;
        }
        else
            cout << "YOU CANNOT THIS MOVE!" << endl;
    }
    else
        cout << "WRONG CHOICE!" << endl;
    location = findLocation();
}

int Board::invCount(){
    int count = 0;
    for (int i=0;i<(size1*size2)-1;i++)
        for (int j=i+1;j<size1*size2;j++)
            if(board[i]>board[j])
                count++;
    return count;
}

bool Board:: isSolved(){
    int count = invCount();
    return (count % 2 == 0);
}

int Board::numberMoves(){
    return numberOfMoves;
}

int Board::findLocation(){
    for(int i=0;i<size1*size2;i++){
        if(board[i] == -1)
            location = i;
    }
    return location;
}


int Board::endGameControl(){   // All numbers are ordered from small to large and check that the space is at the end. If itis true, return 1.
    int control = 0;
    if(location == size1 * size2 - 1){
        for(int i=0;i<size1*size2-1;i++){
            for(int j=i+1;j<size1*size2-1;j++){
                if(board[i] != 0){
                    if(board[i] < board[j])
                        control = 1;
                    else{
                        control = 0;
                        return control;
                    }
                }
            }
        }
    }
    return control;
}

void Board::reset(){    // Final solution
    int temp;
    for(int i=0;i<size1*size2;i++){
        for(int j=i+1;j<size1*size2;j++){   //Bubble short
            if(board[i] > board[j]){
                temp = board[i];
                board[i] = board[j];
                board[j] = temp;
            }
        }
    }
    temp = board[0];
    for(int i=0;i<size1*size2;i++)
        board[i] = board[i+1];
    board[size1*size2-1] = temp;
}

void Board::shuffleBoard(){    // takes two random coordinates and makes up the displacement and repeats this size*size time.
    int control = 0;
    int randomLocation1, randomLocation2, temp;
    while(control == 0){
        reset();  // Takes the board final solution
        for(int i=0;i<size1*size2;i++){
            randomLocation1 = (rand()%(size1*size2));
            randomLocation2 = (rand()%(size1*size2));
            temp = board[randomLocation1];
            board[randomLocation1] = board[randomLocation2];
            board[randomLocation2] = temp;
        }
        if(isSolved() == 1){   // Checks the board to be soluble
            control = 1;
        }
    }
}

void Board::writeToFile(string name){
    int i;
    ofstream myFile;
    myFile.open(name);
    for(i=0;i<size1*size2;i++){
    	if(i % size2 == 0){
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
    	if((i % size2) == (size2 - 1))
            myFile << endl;
    }
}

int Board::height(){
    return size1;
}
int Board::width(){
    return size2;
}

void Board::boardFill(){
    int i;
    int randomNumber;
    for(i=0;i<size1*size2;i++)
        board[i] = -1;
    int control = 0;
    while(control == 0){
        for(i=1;i<size1*size2;i++){
            randomNumber = (rand()%(size1*size2));
            if(board[randomNumber] == -1)
                board[randomNumber] = i;
            else
                i--;
        }
        if(isSolved() == 1){
            control = 1;
        }
        else{
            for(i=0;i<size1*size2;i++)
                board[i] = -1;
        }
    }
}

void Board::readFromFile(string answer){
    string line;
    char arr[500];
    fstream myfile(answer);
    int arrSize = 0, temp = 0;
    if(myfile.is_open()){
        while(getline(myfile,line )){
            size1++;
            for(int i=0;i<38;i++){
            	if(line[i] == '\0')
            		break;
                arr[i] = line[i];
                arrSize++;
            }
            size2 = convert(arr,arrSize,temp);
            arrSize = 0;
        }
        myfile.close();
    }
    else cout << "Unable to open file" << endl;
}

int Board::convert(char arr[], int size, int &numLoc){
    int width = 0;
    for(int i=0;i<size;i++){
        if(arr[i] <= '9' && arr[i] >= '0'){
            if(arr[i] == '0'){
                if(arr[i+1] == '0'){
                    board[numLoc] = arr[i] - 48;
                    numLoc = numLoc + 1;
                    i++;
                }
                else{
                    board[numLoc] = arr[i+1] - 48;
                    numLoc = numLoc + 1;
                    i++;
                }
            }
            else{
                int num1 = arr[i] - 48;
                int num2 = arr[i+1] - 48;
                board[numLoc] = num1*10 + num2;
                numLoc = numLoc + 1;
                i++;
            }
        }
        if(arr[i] == 'b'){
            board[numLoc] = -1;
            numLoc = numLoc + 1;
            i++;
        }
        if(arr[i] == ' ')
            width = width + 1;
    }
    width = width + 1;
    return width;
}

void Board::setSize(int height, int width){
    size1 = height;
    size2 = width;
}

void Board::updateBoard(int arr[]){
    for(int i=0;i<size1*size2;i++)
        board[i] = arr[i];
}

void Board::updateMove(){
    numberOfMoves++;
}
