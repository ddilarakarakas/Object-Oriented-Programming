#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "NPuzzle.h"
using namespace std;

NPuzzle::NPuzzle(){
    Board temp;
    boards.push_back(temp);
    numberBoards = 0;
}

NPuzzle::Board::Board(){
    vector<int> temp;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            temp.push_back(-1);
        }
        vectorBoard.push_back(temp);
        temp.empty();
    }
    moveLast = 'S';
    moveCount = 0;
    numberBoard = 0;
    location = 0;
    size1 = 0;
    size2 = 0;
}

void NPuzzle::Board::print(){
    int board[size1*size2];
    ConvertToArray(board);
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
    ConvertToVector(board);
}

void NPuzzle::Board::reset(){
    int board[size1*size2];
    ConvertToArray(board);
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
    ConvertToVector(board);
}

void NPuzzle::Board::setSize(int height, int width){
    size1 = height;
    size2 = width;
}

void NPuzzle::Board::move(char choice){
    int flag = 0;
    int board[size1*size2];
    ConvertToArray(board);
    location = findLocation();
    if(choice == 'R' || choice == 'r'){
        if(rightControl() == 1){
            board[location] = board[location+1];
            board[location+1] = -1;
            moveCount++;
            flag = 1;
        }
        else
            cout << "YOU CANNOT THIS MOVE!" << endl;
    }
    else if(choice == 'L' || choice == 'l'){
        if(leftControl() == 1){
            board[location] = board[location-1];
            board[location-1] = -1;
            moveCount++;
            flag = 1;
        }
        else
            cout << "YOU CANNOT THIS MOVE!" << endl;
    }
    else if(choice == 'U' || choice == 'u'){
        if(upControl() == 1){
            board[location] = board[location-size2];
            board[location-size2] = -1;
            moveCount++;
            flag = 1;
        }
        else
            cout << "YOU CANNOT THIS MOVE!" << endl;
    }
    else if(choice == 'D' || choice == 'd'){
        if(downControl() == 1){
            board[location] = board[location+size2];
            board[location+size2] = -1;
            moveCount++;
            flag = 1;
        }
        else
            cout << "YOU CANNOT THIS MOVE!" << endl;
    }
    else
        cout << "WRONG CHOICE!" << endl;
    location = findLocation();
    ConvertToVector(board);
    if(flag == 1)
         moveLast = choice;
    else
        moveLast = 'S';
}

int NPuzzle::Board::numberOfBoards()const{
    return numberBoard;
}

char NPuzzle::Board::lastMove()const{
    return moveLast;
}

int NPuzzle::Board::numberOfMoves()const{
    return moveCount;
}

int NPuzzle::Board::endGameControl(){ // All numbers are ordered from small to large and check that the space is at the end. If itis true, return 1.
    int board[size1*size2];
    ConvertToArray(board);
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

int NPuzzle::Board::findLocation(){
    int board[size1*size2];
    ConvertToArray(board);
    for(int i=0;i<size1*size2;i++){
        if(board[i] == -1)
            location = i;
    }
    return location;
}

int NPuzzle::Board::downControl(){
    location = findLocation();
    int board[size1*size2];
    ConvertToArray(board);
    int control = 0;
    if(location >= size1*size2 - size2 && location <= size1*size2 - 1)
        control = 0;
    else{
        if(board[location+size2] == 0)
            control = 0;
        else
            control = 1;
    }
    ConvertToVector(board);
    return control;
}

int NPuzzle::Board::rightControl(){
    location = findLocation();
    int board[size1*size2];
    ConvertToArray(board);
    int control = 0;
    if((location % size2) == (size2 - 1))
        control = 0;
    else{
        if(board[location+1] == 0)
            control = 0;
        else
            control = 1;
    }
    ConvertToVector(board);
    return control;
}

int NPuzzle::Board::leftControl(){
    location = findLocation();
    int board[size1*size2];
    ConvertToArray(board);
    int control = 0;
    if(location % size2 == 0)
        control = 0;
    else{
        if(board[location-1] == 0)
            control = 0;
        else
            control = 1;
    }
    ConvertToVector(board);
    return control;
}

int NPuzzle::Board::upControl(){
    location = findLocation();
    int board[size1*size2];
    ConvertToArray(board);
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

int NPuzzle::Board::invCount(){
    int board[size1*size2];
    ConvertToArray(board);
    int count = 0;
    for (int i=0;i<(size1*size2)-1;i++)
        for (int j=i+1;j<size1*size2;j++)
            if(board[i]>board[j])
                count++;
    return count;
}

bool NPuzzle::Board::isSolved(){
    int count = invCount();
    return (count % 2 == 0);
}

void NPuzzle::Board::ConvertToArray(int arr[]){
    int temp, k = 0;
    for(int i=0;i<size1;i++){
        for(int j=0;j<size2;j++){
            temp = vectorBoard[i][j];
            arr[k] = temp;
            k++;
        }
    }
}

void NPuzzle::Board::ConvertToVector(int arr[]){
    int k = 0;
    for(int i=0;i<size1;i++){
        vector<int> temp;
        for(int j=0;j<size2;j++){
            temp.push_back(arr[k]);
            k++;
        }
        for(int j=0;j<size2;j++)
            vectorBoard[i][j] = temp[j];
        temp.empty();
    }
}

void NPuzzle::Board::boardFill(){
    int board[size1*size2];
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
    ConvertToVector(board);
}

void NPuzzle::Board::readFromFile(string answer){
    string line;
    char arr[500];
    fstream myfile(answer);
    int arrSize = 0, temp = 0;
    size1 = 0;
    if(myfile.is_open()){
        while(getline(myfile,line)){
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

int NPuzzle::Board::convert(char arr[], int size, int &numLoc){
    int width = 0;
    for(int i=0;i<size;i++){
        if(arr[i] <= '9' && arr[i] >= '0'){
            if(arr[i] == '0'){
                if(arr[i+1] == '0'){
                    fileBoard[numLoc] = arr[i] - 48;
                    numLoc = numLoc + 1;
                    i++;
                }
                else{
                    fileBoard[numLoc] = arr[i+1] - 48;
                    numLoc = numLoc + 1;
                    i++;
                }
            }
            else{
                int num1 = arr[i] - 48;
                int num2 = arr[i+1] - 48;
                fileBoard[numLoc] = num1*10 + num2;
                numLoc = numLoc + 1;
                i++;
            }
        }
        if(arr[i] == 'b'){
            fileBoard[numLoc] = -1;
            numLoc = numLoc + 1;
            i++;
        }
        if(arr[i] == ' ')
            width = width + 1;
    }
    width = width + 1;
    ConvertToVector(fileBoard);
    return width;
}

void NPuzzle::Board::writeToFile(string name){
    int board[size1*size2];
    ConvertToArray(board);
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

int NPuzzle::Board::getHeight()const{
    return size1;
}

int NPuzzle::Board::getWidth()const{
    return size2;
}

void NPuzzle::Board::shuffleBoard(){// takes two random coordinates and makes up the displacement and repeats this size*size time.
    int board[size1*size2];
    int control = 0;
    int randomLocation1, randomLocation2, temp;
    while(control == 0){
        ConvertToArray(board);
        reset();  // Takes the board final solution
        for(int i=0;i<size1*size2;i++){
            randomLocation1 = (rand()%(size1*size2));
            randomLocation2 = (rand()%(size1*size2));
            temp = board[randomLocation1];
            board[randomLocation1] = board[randomLocation2];
            board[randomLocation2] = temp;
        }
        ConvertToVector(board);
        if(isSolved() == 1)  // Checks the board to be soluble
            control = 1;
    }
}

bool NPuzzle::Board::operator ==(const Board& game1){
    return(game1.vectorBoard == vectorBoard);
}

void NPuzzle::Board::printReport(){
    cout << "Total number of moves: " << moveCount << endl;
    if(endGameControl() == 1)
        cout << "Problem solved!" << endl;
    else
        cout << "Problem didn't solve!" << endl;
}

void NPuzzle::Board::moveRandom(){
    int board[size1*size2];
    ConvertToArray(board);
    int randomLocation;
    int temp;
    randomLocation = (rand()%(size1*size2));
    temp = board[randomLocation];
    board[randomLocation] = board[location];
    board[location] = temp;
    moveCount++;
    ConvertToVector(board);
}

int NPuzzle::Board::control(){
    if(endGameControl() == 1){
        cout << "End game! Total Move: " << moveCount;
        return 1;
    }
    else
        return 0;
}

int NPuzzle::Board::fileControl(){
    int gameBoard[size1*size2];
    ConvertToArray(gameBoard);
    int control = -1;
    for(int i=0;i<size1*size2;i++){
        if(gameBoard[i] == 0){
            control = 0;
        }
        else
            control = 1;
    }
    return control;
}

void NPuzzle::print(){
    boards[numberBoards].print();
}

void NPuzzle::printReport(){
    boards[numberBoards].printReport();
}

void NPuzzle::readFromFile(string answer){
    boards[numberBoards].readFromFile(answer);
}

void NPuzzle::writeToFile(string answer){
    boards[numberBoards].writeToFile(answer);
}

void NPuzzle::shuffle(){
    boards[numberBoards].shuffleBoard();
}

void NPuzzle::reset(){
    boards[numberBoards].reset();
    numberBoards = 0;
}

void NPuzzle::setSize(int height,int width){
    boards[numberBoards].setSize(height,width);
}

void NPuzzle::moveRandom(){
    boards[numberBoards].moveRandom();
}

void NPuzzle::move(char move){
    boards[numberBoards].move(move);
}

void NPuzzle::printAction()const{
    cout << "INPUT \t ACTION" << endl
    << "L : \t\t Moves the empty cell left if there is room" << endl
    << "R : \t\t Moves the empty cell right if there is room" << endl
    << "U : \t\t Moves the empty cell up if there is room" << endl
    << "D : \t\t Moves the empty cell down if there is room" << endl
    << "S : \t\t Shuffle- takes the board to the final solution, and makes size*size random moves to shuffle the board." << endl
    << "V : \t\t Solves the problem from the current configuration using the new intelligent algorithm." << endl
    << "T : \t\t Prints a report about how many moves have been done and if the solution is found" << endl
    << "E : \t\t Asks a file name and saves the current board configuration as a loadable shape file." << endl
    << "O : \t\t Asks a file name and loads the current board configuration from the shape file." << endl
    << "Q : \t\t Quits the game" << endl << endl << endl;
}

void NPuzzle::boardFill(){
    boards[numberBoards].boardFill();
}

int NPuzzle::control(){
    return  boards[numberBoards].control();
}

int NPuzzle::fileControl(){
    return boards[numberBoards].fileControl();
}

int NPuzzle::getHeight()const{
    return boards[numberBoards].getHeight();
}

int NPuzzle::getWidth()const{
    return boards[numberBoards].getWidth();
}

void NPuzzle::ConvertToVector(int arr[]){
    boards[numberBoards].ConvertToVector(arr);
}

void NPuzzle::ConvertToArray(int arr[]){
    boards[numberBoards].ConvertToArray(arr);
}

ostream& operator <<(ostream& outputStream,NPuzzle &game){
    int size1 = game.getHeight();
    int size2 = game.getWidth();
    int board[size1*size2];
    game.ConvertToArray(board);
    int i;
    for(i=0;i<size1*size2;i++){
        if(board[i] == -1)
            outputStream << "bb ";
        else{
            if((board[i] >= 0) && (board[i] <= 9))
                outputStream << "0" << board[i] << " ";
            else
                outputStream << board[i] << " ";
        }
        if((i % size2) == (size2 - 1))
            outputStream << endl;
    }
    return outputStream;
}

istream& operator >>(istream& inputStream,NPuzzle &game){
    int size1;
    int size2;
    cout << endl << "Enter the height : ";
    inputStream >> size1;
    cout << endl << "Enter the width : ";
    inputStream >> size2;
    game.setSize(size1, size2);
    return inputStream;
}

int NPuzzle::Board::operator ()(const Board&, int x,int y){
    int index;
    int arr[size1*size2];
    ConvertToArray(arr);
    index = arr[(size2*(x-1))+(y-1)];
    return index;
}

bool NPuzzle::Board::solvePuzzle(vector<Board>  boards1,int moveCount1, int numberBoards1){
    if(boards1[moveCount1].endGameControl(boards1[moveCount1]) == true){
        boards1[moveCount1].print();
        cout << "END GAME! MOVE COUNT: " << moveCount1 << endl;
        return true;
    }
    int count = 0;
    Board tempBoard;
    tempBoard = boards1[moveCount1];
    if(tempBoard.rightControl() == 1){
        tempBoard.move('r');
        if(!(controlBoard(tempBoard, boards1))){
            boards1.push_back(tempBoard);
            count++;
            boards1[count+numberBoards1].print();
            cout << endl;
        }
    }
    tempBoard = boards1[moveCount1];
    if(tempBoard.leftControl() == 1){
        tempBoard.move('l');
        if(!(controlBoard(tempBoard, boards1))){
            boards1.push_back(tempBoard);
            count++;
            boards1[count+numberBoards1].print();
            cout << endl;
        }
    }
    tempBoard = boards1[moveCount1];
    if(tempBoard.downControl() == 1){
        tempBoard.move('d');
        if(!(controlBoard(tempBoard, boards1))){
            boards1.push_back(tempBoard);
            count++;
            boards1[count+numberBoards1].print();
            cout << endl;
        }
    }
    tempBoard = boards1[moveCount1];
    if(tempBoard.upControl() == 1){
        tempBoard.move('u');
        if(!(controlBoard(tempBoard, boards1))){
            boards1.push_back(tempBoard);
            count++;
            boards1[count+numberBoards1].print();
            cout << endl;
        }
    }
    numberBoards1 += count;
    solvePuzzle(boards1,moveCount1+1,numberBoards1);
    return false;
}

bool NPuzzle::Board::controlBoard(Board temp, vector<Board> boards){
    for(int i=0;i<boards.size();i++){
        if(boards[i] == temp)
            return true;
    }
    return false;
}

void NPuzzle::solvePuzzle(){
    int moveCount = 0;
    boards[numberBoards].solvePuzzle(boards,moveCount,numberBoards);
}

bool NPuzzle::Board::endGameControl(Board board){
    int arrayBoard[size1*size2];
    ConvertToArray(arrayBoard);
    int tempLocation = board.findLocation();
    bool control = false;
    if(tempLocation == size1 * size2 - 1){
        for(int i=0;i<size1*size2-1;i++){
            for(int j=i+1;j<size1*size2-1;j++){
                if(arrayBoard[i] != 0){
                    if(arrayBoard[i] < arrayBoard[j])
                        control = true;
                    else{
                        return false;
                    }
                }
            }
        }
    }
    return control;
}
