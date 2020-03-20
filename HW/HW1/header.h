#ifndef header_h
#define header_h
#include <iostream>
#include <cstdlib>
#include <ctime>

void game(void);
void printAction(void);
void boardFill(int [],int);
void printBoard(int [],int);
void play(int[],int);
int findLocation(int[],int);
int EndGAmeControl(int[],int,int);
int invCount(int [],int);
bool solvable(int [], int);
void goalState(int [],int);
void shuffleBoard(int [],int);
int leftControl(int,int);
int rightControl(int,int);
int upControl(int,int);
int downControl(int,int);
void intelligent(int [],int,int);
int absolute(int);
void rightMove(int [],int,int);
void leftMove(int [],int,int);
void upMove(int [],int,int);
void downMove(int [],int,int);

#endif /* header_h */
