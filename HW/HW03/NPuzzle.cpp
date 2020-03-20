#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "NPuzzle.h"
#include "Board.h"
using namespace std;

void NPuzzle::startSet(){
    playGround.set();
    set();
}

void NPuzzle::set(){
    height = playGround.height();
    width = playGround.width();
    location = playGround.findLocation();
    playGround.fillTempBoard();
    moveCount = playGround.numberMoves();
    for(int i=0;i<81;i++)
        gameBoard[i] = playGround.tempBoard[i];
}

void NPuzzle::print()const{
    playGround.print();
}

void NPuzzle::printReport(){
    set();
    cout << "Total number of moves: " << moveCount << endl;
    if(playGround.endGameControl() == 1)
        cout << "Problem solved!" << endl;
    else
        cout << "Problem didn't solve!" << endl;
}

void NPuzzle::readFromFile(string answer){
    startSet();
    playGround.readFromFile(answer);
    set();
    moveCount = 0;
}

void NPuzzle::writeToFile(string answer){
	playGround.updateBoard(gameBoard);
    playGround.writeToFile(answer);
    set();
    moveCount = 0;
}

void NPuzzle::shuffle(){
    set();
    int control = 0;
    int randomLocation1, randomLocation2, temp;
    while(control == 0){
        playGround.reset();  // Takes the board final solution
        for(int i=0;i<height*width;i++){
            randomLocation1 = (rand()%(height*width));
            randomLocation2 = (rand()%(height*width));
            temp = gameBoard[randomLocation1];
            gameBoard[randomLocation1] = gameBoard[randomLocation2];
            gameBoard[randomLocation2] = temp;
        }
        playGround.updateBoard(gameBoard);
        playGround.findLocation();
        if(playGround.isSolved() == 1){   // Checks the board to be soluble
            control = 1;
            set();
        }
    }
}

void NPuzzle::reset(){
    playGround.reset();
    set();
}

void NPuzzle::setSize(int tempSize1, int tempSize2){
    playGround.setSize(tempSize1, tempSize2);
    height = playGround.height();
    width = playGround.width();
}

void NPuzzle::moveRandom(){
    set();
    int randomLocation;
    int temp;
    randomLocation = (rand()%(height*width));
    temp = gameBoard[randomLocation];
    gameBoard[randomLocation] = gameBoard[location];
    gameBoard[location] = temp;
    playGround.updateBoard(gameBoard);
    playGround.findLocation();
    playGround.updateMove();
}

void NPuzzle::moveIntelligent(){
    set();
    int controlLeft = playGround.leftControl();
    int controlRight = playGround.rightControl();
    int controlUp = playGround.upControl();
    int controlDown = playGround.downControl();
    int difference = 0, flag = 0, temp;
    char direction = '\0';
    if(controlLeft == 1){
        if(flag == 0){                                  //Enters condition if performing first check
            difference = (location + 1) - (gameBoard[location-1]);
            difference = abs(difference);      //So that the difference between them is not negative
            direction = 'L';
            flag = 1;
        }
        else{ // Otherwise it will compare with the previous number, compare the difference between where it should be and where it is and find the little one.
            temp = (location + 1) - (gameBoard[location-1]);
            temp = abs(temp);    // so that the difference between them is not negative
            if(temp < difference){
                difference = temp;
                direction = 'L';
            }
        }
    }
    if(controlRight == 1){ // It does do same but right to
        if(flag == 0){
            difference = (location + 1) - (gameBoard[location+1]);
            difference = abs(difference);
            direction = 'R';
            flag = 1;
        }
        else{
            temp = (location + 1) - (gameBoard[location+1]);
            temp = abs(temp);
            if(temp < difference){
                difference = temp;
                direction = 'R';
            }
        }
    }
    if(controlDown == 1){ // It does do same but down to
        if(flag == 0){
            difference = (location + 1) - (gameBoard[location+width]);
            difference = abs(difference);
            direction = 'D';
            flag = 1;
        }
        else{
            temp = (location + 1) - (gameBoard[location+width]);
            temp = abs(temp);
            if(temp < difference){
                difference = temp;
                direction = 'D';
            }
        }
    }
    if(controlUp == 1){  // It does do same but up to
        if(flag == 0){
            difference = (location +1) - (gameBoard[location-width]);
            difference = abs(difference);
            direction = 'U';
            flag = 1;
        }
        else{
            temp = (location +1) - (gameBoard[location-width]);
            temp = abs(temp);
            if(temp < difference){
                difference = temp;
                direction = 'U';
            }
        }
    }
    cout << "Intelligent move chooses :  " << direction << endl;
    playGround.move(direction);
    playGround.print();
    set();
}

void NPuzzle::move(char move){
    playGround.updateBoard(gameBoard);
    playGround.move(move);
    set();
}

void NPuzzle::solvePuzzle(){
    set();
    int control = 0;
    int valueTemp = 0, locationTemp = 0;
    int moveCount = 0;
    int locationControl = playGround.findLocation();
    int flag = 0, temp;
    if(locationControl == height*width - 1){
    	int controloop = 0;
    	int tempLocation;
    	while(controloop == 0){
    		tempLocation = (rand()%(height*width-2));
    		if(gameBoard[tempLocation] == 0)
    			controloop = 0;
    		else
    			controloop = 1;
    	}
    	gameBoard[locationControl] = gameBoard[tempLocation];
    	gameBoard[tempLocation] = -1;
    	moveCount++;
        playGround.updateBoard(gameBoard);
        location = playGround.findLocation();
        cout << "New Move 1" << endl;
        playGround.print();
    }
    for(int i=0;i<height*width;i++){
        if(gameBoard[i] == 0)
            flag = 1;
        else
        	flag = 0;
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
            for(int i=0;i<j;i++){
            	if(tempArray[i] == -1)
            		temp = i;
         	}
            for(int i=0;i<j;i++){
                if(temp == j - 1){
                	locationTemp = (rand()%(j-2));
                	valueTemp = tempArray[locationTemp];
                	break;
                }
                if(tempArray[i] == temp + 1){
                    valueTemp = tempArray[i];
                    locationTemp = i;
                }
            }
            tempArray[temp] = valueTemp;
            tempArray[locationTemp] = -1;
            moveCount++;
            for(int i=0;i<j-1;i++){
            	int f = 0;
            	for(int k=i+1;k<j-1;k++){
            		if(tempArray[i] < tempArray[k])
            			loopControl = 1;
            		else{
            			f = 1;
            			loopControl = 0;
            			break;
            		}
            	}
            	if(f == 1)
            		break;
            }
            j = 0;
            for(int i=0;i<height*width;i++){
                if(gameBoard[i] != 0){
                    gameBoard[i] = tempArray[j];
                    j++;
                }
            }
            playGround.updateBoard(gameBoard);
            location = playGround.findLocation();
            cout << "Nev Move" << endl;
            playGround.print();
            
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
        playGround.updateBoard(gameBoard);
        location = playGround.findLocation();
        cout << "New Move" << endl;
        playGround.print();
        control = playGround.endGameControl();
        if(control == 1)
        	cout << "Problem Solved! Total Moves: " << moveCount << endl;
    }
}

void NPuzzle::printAction()const{
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
         << "O : \t\t Asks a file name and loads the current board configuration from the shape file." << endl
         << "Q : \t\t Quits the game" << endl << endl << endl;
}

void NPuzzle::boardFill(){
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
        playGround.updateBoard(gameBoard);
        location = playGround.findLocation();
        if(playGround.isSolved() == 1){
            control = 1;
        }
        else{
            for(i=0;i<height*width;i++)
                gameBoard[i] = -1;
        }
    }
}

int NPuzzle::control(){
    set();
    if(playGround.endGameControl() == 1){
        cout << "End game! Total Move: " << moveCount;
        return 1;
    }
    else
        return 0;
}

int NPuzzle::fileControl(){
	set();
    int control;
    for(int i=0;i<width*height;i++){
        if(gameBoard[i] == 0){
            control = 0;
        }
        else
            control = 1;
    }
    return control;
}
