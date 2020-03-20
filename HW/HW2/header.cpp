#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "header.h"
using namespace std;

inline void printBoard(int board[],int size1,int size2){
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

const void printAction(void){
    cout << "INPUT \t ACTION" << endl
    << "L : \t\t Moves the empty cell left if there is room" << endl
    << "R : \t\t Moves the empty cell right if there is room" << endl
    << "U : \t\t Moves the empty cell up if there is room" << endl
    << "D : \t\t Moves the empty cell down if there is room" << endl
    << "I : \t\t Makes an “intelligent” move for you. Intelligent move moves the blank tile in a way that after the move, the tiles are closer to their final positions. You may add extra intelligence if you like!" << endl
    << "S : \t\t Shuffle- takes the board to the final solution, and makes size*size random moves to shuffle the board." << endl
    << "V : \t\t Solves the problem from the current configuration using the new intelligent algorithm." << endl
    << "T : \t\t Prints a report about how many moves have been done and if the solution is found" << endl
    << "E : \t\t Asks a file name and saves the current board configuration as a loadable shape file." << endl
    << "Y : \t\t Asks a file name and loads the current board configuration from the shape file." << endl
    << "Q : \t\t Quits the game" << endl << endl << endl;
}

void shuffleBoard(int board[],int size1,int size2){    // takes two random coordinates and makes up the displacement and repeats this size*size time.
    int control = 0;
    int randomLocation1, randomLocation2, temp;
    while(control == 0){
        goalState(board, size1, size2);  // Takes the board final solution
        for(int i=0;i<size1*size2;i++){
            randomLocation1 = (rand()%(size1*size2));
            randomLocation2 = (rand()%(size1*size2));
            temp = board[randomLocation1];
            board[randomLocation1] = board[randomLocation2];
            board[randomLocation2] = temp;
        }
        if(solvable(board, size1*size2) == 1){   // Checks the board to be soluble
            control = 1;
            printBoard(board, size1,size2);
        }
    }
}

void goalState(int board[],int size1, int size2){   // final solution
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

int findLocation(int board[],int size1,int size2){
    int temp = 0;
    for(int i=0;i<size1*size2;i++){
        if(board[i] == -1)
            temp = i;
    }
    return temp;
}

int EndGAmeControl(int board[], int location, int size1, int size2){   // All numbers are ordered from small to large and check that the space is at the end.
    int control = 0;                                                   // If itis true, return 1.
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

int leftControl(int board[],int location,int size1,int size2){
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

int rightControl(int board[],int location ,int size1,int size2){
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

int upControl(int board[],int location,int size1, int size2){
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

int downControl(int board[],int location,int size1,int size2){
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

int absolute(int num){
    if(num < 0)
        num = num * (-1);
    return num;
}

void rightMove(int board[],int location,int size1, int size2){
    board[location] = board[location+1];
    board[location+1] = -1;
}

void leftMove(int board[],int location,int size1, int size2){
    board[location] = board[location-1];
    board[location-1] = -1;
}

void upMove(int board[],int location,int size1,int size2){
    board[location] = board[location-size2];
    board[location-size2] = -1;
}

void downMove(int board[],int location,int size1,int size2){
    board[location] = board[location+size2];
    board[location+size2] = -1;
}

int convert(int number[],char arr[],int size, int *numLoc){
    int width = 0;
    for(int i=0;i<size;i++){
        if(arr[i] <= '9' && arr[i] >= '0'){
            if(arr[i] == '0'){
                if(arr[i+1] == '0'){
                    number[*numLoc] = arr[i] - 48;
                    *numLoc = *numLoc + 1;
                    i++;
                }
                else{
                    number[*numLoc] = arr[i+1] - 48;
                    *numLoc = *numLoc + 1;
                    i++;
                }
            }
            else{
                int num1 = arr[i] - 48;
                int num2 = arr[i+1] - 48;
                number[*numLoc] = num1*10 + num2;
                *numLoc = *numLoc + 1;
                i++;
            }
        }
        if(arr[i] == 'b'){
            number[*numLoc] = -1;
            *numLoc = *numLoc + 1;
            i++;
        }
        if(arr[i] == ' ')
            width = width + 1;
    }
    width = width + 1;
    return width;
}

void game(){
    printAction();
    cout << "Enter the height : ";
    int height;
    cin >> height;
    cout << "Enter the width : ";
    int width;
    cin >> width;
    int board[100];
    boardFill(board, height, width);
    playGame(board,height,width);
}

void playGame(int board[],int height,int width){
    char move;
    auto moveCount = 0;
    auto location = findLocation(board, height, width);
    auto control = 0, flag = 0 , fileFlag = 0;
    printBoard(board, height, width);
    while(control == 0){
        if(flag == 1)
            break;
        cout << "Your Choose: ";
        cin >> move;
        if(move == 'L' || move == 'l'){
            if(leftControl(board,location, height, width) == 0)
                cout << "YOU CANNOT THIS MOVE" << endl;
            else{
                leftMove(board, location, height, width);
                location = findLocation(board, height, width);
                printBoard(board, height, width);
                moveCount++;
            }
        }
        else if(move == 'R' || move == 'r'){
            if(rightControl(board, location, height, width) == 0)
                cout << "YOU CANNOT THIS MOVE" << endl;
            else{
                rightMove(board, location, height, width);
                location = findLocation(board, height, width);
                printBoard(board, height, width);
                moveCount++;
            }
        }
        else if(move == 'U' || move == 'u'){
            if(upControl(board, location, height, width) == 0)
                cout << "YOU CANNOT THIS MOVE" << endl;
            else{
                upMove(board, location, height, width);
                location = findLocation(board, height, width);
                printBoard(board, height, width);
                moveCount++;
            }
        }
        else if(move == 'D' || move == 'd'){
            if(downControl(board, location, height, width) == 0)
                cout << "YOU CANNOT THIS MOVE" << endl;
            else{
                downMove(board, location, height, width);
                location = findLocation(board, height, width);
                printBoard(board, height, width);
                moveCount++;
            }
        }
        else if(move == 'Q' || move == 'q'){
            control = 1;
            cout << "Total number of moves " << moveCount << endl;
            break;
        }
        else if(move == 'S' || move == 's'){
            shuffleBoard(board, height, width);
        }
        else if(move == 'I' || move == 'i'){
            intelligent(board, location, height,width);
            location = findLocation(board, height, width);
            moveCount++;
        }
        else if(move == 'V' || move == 'v'){
            moveCount = newIntelligent(board, location, height, width);
            location = findLocation(board, height, width);
            fileFlag = 1;
            
        }
        else if(move == 'T' || move == 't'){
            int temp = EndGAmeControl(board, location, height, width);
            cout << "Total number of moves: " << moveCount ;
            if(temp == 1)
                cout << "Problem Solved! " << endl;
            else
                cout << "Problem Did Not Solve! " << endl;
        }
        else if(move == 'E' || move == 'e'){
            string file;
            cout << endl << "Please, Enter the file name (example.txt) for saved board : ";
            cin >> file;
            writeFile(board, height, width, file);
        }
        else if(move == 'Y' || move == 'y'){
            string line;
            string fileName;
            char lineFile[500];
            int number[500];
            cout << "Enter the file name (exeample.txt) for open board: " ;
            cin >> fileName;
            fstream myFile(fileName);
            int arrSize = 0, temp = 0, tempHeight = 0, tempWidth = 0;
            if (myFile.is_open()){
                while ( getline (myFile,line) ){
                    tempHeight++;
                    for(int i=0;i<26;i++){
                        lineFile[i] = line[i];
                        arrSize++;
                    }
                    tempWidth = convert(number,lineFile,arrSize,&temp);
                }
                myFile.close();
            }
            else
                cout << "Unable to open file" << endl;
            width = tempWidth;
            height = tempHeight;
            playGame(number, height, width);
            
            flag = 1;
        }
        else
            cout << "WRONG INPUT!!" << endl;
        control = EndGAmeControl(board, location, height, width);
        if(control == 1)
            cout << "Problem solved! \nTotal number of moves: " << moveCount << endl;
        if(fileFlag == 1)
            break;
    }
}

int newIntelligent(int gameBoard[],int location,int height,int width){
    int control = 0;
    int valueTemp = 0, locationTemp = 0;
    int moveCount = 0;
    
    int flag = 0, temp;
    for(int i=0;i<height*width;i++){
        if(gameBoard[i] == 0)
            flag = 1;
    }
    if(flag == 1){
        int loopControl = 0, j;
        while(loopControl == 0){
            int tempArray[100];
            j = 0;
            for(int i=0;i<height*width;i++){
                if(gameBoard[i] != 0){
                    tempArray[j] = gameBoard[i];
                    j++;
                    gameBoard[i] = -2;
                }
            }
            temp = findLocation(tempArray, 1, j);
            for(int i=0;i<j;i++){
                if(locationTemp == j - 1){
                    int randomControl = 0;
                    while(randomControl == 0){
                        locationTemp = (rand()%(j));
                        if(tempArray[locationTemp] != 0)
                            randomControl = 1;
                    }
                    valueTemp = tempArray[locationTemp];
                }
                if(tempArray[i] == temp + 1){
                    valueTemp = tempArray[i];
                    locationTemp = i;
                }
            }
            tempArray[temp] = valueTemp;
            tempArray[locationTemp] = -1;
            moveCount++;
            j = 0;
            for(int i=0;i<height*width;i++){
                if(gameBoard[i] != 0){
                    gameBoard[i] = tempArray[j];
                    j++;
                }
            }
            location = findLocation(tempArray, 1, j);
            cout << "Nev Move" << endl;
            printBoard(gameBoard, height, width);
            loopControl = EndGAmeControl(tempArray, location, 1, j);
        }
        control = 1;
        cout << "Problem solved! \nTotal number of moves: " << moveCount << endl;
    }
    
    
    while(control == 0){
        for(int i=0;i<height*width;i++){
            if(gameBoard[i] != 0){
                if(locationTemp == height*width - 1){
                    locationTemp = (rand()%(height*width));
                    valueTemp = gameBoard[locationTemp];
                }
                if(gameBoard[i] == location + 1){
                    valueTemp = gameBoard[i];
                    locationTemp = i;
                }
            }
        }
        gameBoard[location] = valueTemp;
        gameBoard[locationTemp] = -1;
        moveCount++;
        location = findLocation(gameBoard, height, width);
        cout << "New Move" << endl;
        printBoard(gameBoard, height, width);
        control = EndGAmeControl(gameBoard, location, height, width);
    }
    return moveCount;
}

void randomMove(int gameBoard[],int location,int height,int width){
    int randomLocation;
    int temp;
    randomLocation = (rand()%(height*width));
    temp = gameBoard[randomLocation];
    gameBoard[randomLocation] = gameBoard[location];
    gameBoard[location] = temp;
}

void writeFile(int board[],int size1,int size2,string name){
    int i;
    ofstream myFile;
    myFile.open(name);
    for(i=0;i<size1*size2;i++){
        if(board[i] == -1)
            myFile << "bb ";
        else{
            if((board[i] >= 0) && (board[i] <= 9))
                myFile << "0" << board[i] << " ";
            else
                myFile << board[i] << " ";
        }
        if((i % size2) == (size2 - 1))
            myFile << endl;
    }
}

void intelligent(int board[],int location,int height, int width){      //Checks the numbers around the space, and moves the number closest to where it should be
    int controlLeft = leftControl(board, location, height, width);
    int controlRight = rightControl(board, location, height,width);
    int controlUp = upControl(board, location, height,width);
    int controlDown = downControl(board, location, height,width);
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
            difference = (location + width) - (board[location+width] - 1);
            difference = absolute(difference);
            direction = 'D';
            flag = 1;
        }
        else{
            temp = (location + width) - (board[location+width] - 1);
            temp = absolute(temp);
            if(temp < difference){
                difference = temp;
                direction = 'D';
            }
        }
    }
    if(controlUp == 1){  // It does do same but up to
        if(flag == 0){
            difference = (location - width) - (board[location-width] - 1);
            difference = absolute(difference);
            direction = 'U';
            flag = 1;
        }
        else{
            temp = (location - width) - (board[location-width] - 1);
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
            rightMove(board, location, height, width);
            break;
        case 'L':
            leftMove(board, location, height, width);
            break;
        case 'U':
            upMove(board, location, height, width);
            break;
        case 'D':
            downMove(board, location, height, width);
            break;
        default:
            break;
    }
    printBoard(board, height,width);
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

void boardFill(int board[],int size1, int size2){
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
        if(solvable(board, size1*size2) == 1){
            control = 1;
        }
        else{
            for(i=0;i<size1*size2;i++)
                board[i] = -1;
        }
    }
}

