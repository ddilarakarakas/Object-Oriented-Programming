#include <iostream>
#include <cstdlib>
#include <ctime>
#include "header.h"
using namespace std;

void game(void){
    printAction();
    cout << "Please enter the problem size" << endl;
    int size;
    cin >> size;
    cout << "Your initial random board is" << endl;
    int playBoard[size*size];
    boardFill(playBoard,size);
    play(playBoard,size);
}

void play(int board[],int size){
    int location = findLocation(board, size);
    int control = 0;
    int moveCount = 0;
    while(control == 0){
        cout << "Your move : ";
        char move;
        cin >> move;
        if(move == 'L' || move == 'l'){
            if(location % size == 0){
                cout << "YOU CANNOT THIS MOVE" << endl;
            }
            else{
                leftMove(board, location, size);
                location = findLocation(board, size);
                printBoard(board, size);
                moveCount++;
            }
        }
        else if(move == 'R' || move == 'r'){
            if(location % size == size - 1){
                cout << "YOU CANNOT THIS MOVE" << endl;
            }
            else{
                rightMove(board, location, size);
                location = findLocation(board, size);
                printBoard(board, size);
                moveCount++;
            }
        }
        else if(move == 'U' || move == 'u'){
            if(location < size){
                cout << "YOU CANNOT THIS MOVE" << endl;
            }
            else{
                upMove(board, location, size);
                location = findLocation(board, size);
                printBoard(board, size);
                moveCount++;
            }
        }
        else if(move == 'D' || move == 'd'){
            if(location >= size*(size-1) && location <= size*size){
                cout << "YOU CANNOT THIS MOVE" << endl;
            }
            else{
                downMove(board, location, size);
                location = findLocation(board, size);
                printBoard(board, size);
                moveCount++;
            }
        }
        else if(move == 'S' || move == 's'){
            shuffleBoard(board, size);
        }
        else if(move == 'I' || move == 'i'){
            intelligent(board, location, size);
            location = findLocation(board, size);
            moveCount++;
        }
        else if(move == 'Q' || move == 'q'){
            control = 1;
            cout << "Total number of moves " << moveCount << endl;
            break;
        }
        else{
            cout << "WRONG INPUT!!" << endl;
        }
        control = EndGAmeControl(board, location, size);
        if(control == 1)
            cout << "Problem solved! \n Total number of moves " << moveCount << endl;
    }
}

void intelligent(int board[],int location,int size){      //Checks the numbers around the space, and moves the number closest to where it should be
    int controlLeft = leftControl(location, size);
    int controlRight = rightControl(location, size);
    int controlUp = upControl(location, size);
    int controlDown = downControl(location, size);
    int difference = 0, flag = 0, temp;
    char direction = '\0';
    if(controlLeft == 1){
        if(flag == 0){                                  //Enters condition if performing first check
            difference = (location - 1) - (board[location-1] - 1);
            difference = absolute(difference);      //So that the difference between them is not negative
            direction = 'L';
            flag = 1;
        }
        else{                                          // Otherwise it will compare with the previous number, compare the difference between where it should be and where it is and find the little one.
            temp = (location - 1) - (board[location-1] - 1);
            temp = absolute(temp);    // so that the difference between them is not negative
            if(temp < difference){
                difference = temp;
                direction = 'L';
            }
        }
    }
    if(controlRight == 1){ // It does do same but right to
        if(flag == 0){
            difference = (location + 1) - (board[location+1] - 1);
            difference = absolute(difference);
            direction = 'R';
            flag = 1;
        }
        else{
            temp = (location + 1) - (board[location+1] - 1);
            temp = absolute(temp);
            if(temp < difference){
                difference = temp;
                direction = 'R';
            }
        }
    }
    if(controlDown == 1){ // It does do same but down to
        if(flag == 0){
            difference = (location + size) - (board[location+size] - 1);
            difference = absolute(difference);
            direction = 'D';
            flag = 1;
        }
        else{
            temp = (location + size) - (board[location+size] - 1);
            temp = absolute(temp);
            if(temp < difference){
                difference = temp;
                direction = 'D';
            }
        }
    }
    if(controlUp == 1){  // It does do same but up to
        if(flag == 0){
            difference = (location - size) - (board[location-size] - 1);
            difference = absolute(difference);
            direction = 'U';
            flag = 1;
        }
        else{
            temp = (location - size) - (board[location-size] - 1);
            temp = absolute(temp);
            if(temp < difference){
                difference = temp;
                direction = 'U';
            }
        }
    }
    cout << "Intelligent move chooses :  " << direction << endl;
    switch(direction){
        case 'R':
            rightMove(board, location, size);
            break;
        case 'L':
            leftMove(board, location, size);
            break;
        case 'U':
            upMove(board, location, size);
            break;
        case 'D':
            downMove(board, location, size);
            break;
        default:
            break;
    }
    printBoard(board, size);
}

void rightMove(int board[],int location,int size){
    board[location] = board[location+1];
    board[location+1] = 0;
}

void leftMove(int board[],int location,int size){
    board[location] = board[location-1];
    board[location-1] = 0;
}

void upMove(int board[],int location,int size){
    board[location] = board[location-size];
    board[location-size] = 0;
}

void downMove(int board[],int location,int size){
    board[location] = board[location+size];
    board[location+size] = 0;
}

int absolute(int num){
    if(num < 0)
        num = num * (-1);
    return num;
}

int leftControl(int location,int size){
    int control;
    if(location % size == 0)
        control = 0;
    else
        control = 1;
    return control;
}

int rightControl(int location ,int size){
    int control;
    if(location % size == 3)
        control = 0;
    else
        control = 1;
    return control;
}

int upControl(int location,int size){
    int control;
    if(location < size)
        control = 0;
    else
        control = 1;
    return control;
}

int downControl(int location,int size){
    int control;
    if(location >= size*(size-1) && location <= size*size)
        control = 0;
    else
        control = 1;
    return control;
}

int EndGAmeControl(int board[], int location, int size){   // all numbers are ordered from small to large and check that the space is at the end. If it is true, return 1.
    int control = 0;
    if(location == size * size - 1){
        for(int i=0;i<size*size;i++){
            for(int j=i+1;j<size*size;j++){
                if(board[i] < board[j])
                    control = 1;
                else{
                    control = 0;
                    return control;
                }
            }
        }
    }
    return control;
}

int findLocation(int board[],int size){
    int temp = 0;
    for(int i=0;i<size*size;i++){
        if(board[i] == 0)
            temp = i;
    }
    return temp;
}

void printAction(void){
    cout << "INPUT \t ACTION" << endl
    << "L \t\t Moves the empty cell left if there is room" << endl
    << "R \t\t Moves the empty cell right if there is room" << endl
    << "U \t\t Moves the empty cell up if there is room" << endl
    << "D \t\t Moves the empty cell down if there is room" << endl
    << "I \t\t Makes an “intelligent” move for you. Intelligent move moves the blank tile in a way that after the move, the tiles are closer to their final positions. You may add extra intelligence if you like!" << endl
    << "S \t\t Shuffle- takes the board to the final solution, and makes size*size random moves to shuffle the board." << endl
    << "Q \t\t Quits the game" << endl << endl << endl;
}

void boardFill(int board[],int size){
    int i;
    int randomNumber;
    for(i=0;i<size*size;i++)
        board[i] = 0;
    int control = 0;
    while(control == 0){
        for(i=1;i<size*size;i++){
            randomNumber = (rand()%(size*size));
            if(board[randomNumber] == 0)
                board[randomNumber] = i;
            else
                i--;
        }
        if(solvable(board, size) == 1){
            control = 1;
            printBoard(board,size);
        }
        else{
            for(i=0;i<size*size;i++)
                board[i] = 0;
        }
    }
}

void shuffleBoard(int board[],int size){    // takes two random coordinates and makes up the displacement and repeats this size*size time.
    int control = 0;
    int randomLocation1, randomLocation2, temp;
    while(control == 0){
        goalState(board, size);  // Takes the board final solution
        for(int i=0;i<size*size;i++){
            randomLocation1 = (rand()%(size*size));
            randomLocation2 = (rand()%(size*size));
            temp = board[randomLocation1];
            board[randomLocation1] = board[randomLocation2];
            board[randomLocation2] = temp;
        }
        if(solvable(board, size) == 1){   // Checks the board to be soluble
            control = 1;
            printBoard(board, size);
        }
    }
}

void goalState(int board[],int size){   // final solution
    int temp;
    for(int i=0;i<size*size;i++){
        for(int j=i+1;j<size*size;j++){   //Bubble short
            if(board[i] > board[j]){
                temp = board[i];
                board[i] = board[j];
                board[j] = temp;
            }
        }
    }
    temp = board[0];
    for(int i=0;i<size*size;i++)
        board[i] = board[i+1];
    board[size*size-1] = temp;
}

int invCount(int board[], int size){
    int count = 0;
    for (int i=0;i<size-1;i++)
        for (int j=i+1;j<size;j++)
            if(board[i]>board[j])
                count++;
    return count;
}

bool solvable(int board[], int size){
    int count = invCount(board,size);
    return (count % 2 == 0);                       // If inversion count is even return true.
}

void printBoard(int board[],int size){
    int i;
    for(i=0;i<size*size;i++){
        if(board[i] == 0)
            cout << " \t";
        else
            cout << board[i] << "\t";
        if((i % size) == (size - 1))
            cout << endl;
    }
}
