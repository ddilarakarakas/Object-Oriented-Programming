#ifndef header_h
#define header_h
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

inline void printBoard(int [],int,int);
const void printAction(void);
void shuffleBoard(int [],int,int);
void goalState(int [],int,int);
int findLocation(int[],int,int);
int EndGAmeControl(int[],int,int,int);
int leftControl(int [],int,int,int);
int rightControl(int [],int,int,int);
int upControl(int [],int,int,int);
int downControl(int [],int,int,int);
int absolute(int);
void rightMove(int [],int,int,int);
void leftMove(int [],int,int,int);
void upMove(int [],int,int,int);
void downMove(int [],int,int,int);
int convert(int [],char [],int , int *);
void game(void);
void playGame(int [],int,int);
void intelligent(int [],int,int,int);
int invCount(int [],int);
bool solvable(int [], int);
void writeFile(int [],int,int,string);
void boardFill(int [],int,int);
void randomMove(int[],int,int,int);
int newIntelligent(int [],int,int,int);



#endif /* header_h */
