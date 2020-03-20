#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "NPuzzle.h"
using namespace std;

int main(){
    NPuzzle game;
    int startControl = 0, controlFile = 0;
    cout << endl << "Do you have a file you want to enter? (Y/N) :  ";
    while(startControl == 0){
        char c;
        cin >> c;
        if(c == 'y'){
            while(controlFile == 0){
                string name;
                cout << endl << "Enter the file name (example.txt) :";
                cin >> name;
                game.readFromFile(name);
                if(game.fileControl() == 1){
                    controlFile = 1;
                    startControl = 1;
                }
            }
        }
        else if(c == 'n'){
            cin >> game;
            game.boardFill();
            startControl = 1;
        }
        else{
            cout << endl << "Wrong input! Try again!!" << endl;
        }
    }
    game.printAction();
    cout << game;
    auto control = 0;
    while(control == 0){
        cout << endl << "Your choice :";
        char choice;
        cin >> choice;
        if(choice=='l'||choice=='r'||choice=='d'||choice=='u'||choice=='L'||choice=='R'||choice=='U'||choice=='D'){
            game.move(choice);
            cout << game;
        }
        else if(choice == 'S' || choice == 's'){
            game.shuffle();
            cout << game;
        }
        else if(choice == 'v' || choice == 'V'){
            game.solvePuzzle();
            control = 1;
            break;
        }
        else if(choice == 'T' || choice == 't'){
            game.printReport();
        }
        else if(choice == 'E' || choice == 'e'){
            cout << endl << "Enter the file name (example.txt) : ";
            string name;
            cin >> name;
            game.writeToFile(name);
            cout << game;
        }
        else if(choice == 'O' || choice == 'o'){
            string name;
            cout << endl << "Enter the file name (example.txt) :";
            cin >> name;
            game.readFromFile(name);
            cout << game;
        }
        else if(choice == 'Q' || choice == 'q')
            control = 1;
        else
            cout << endl << "Wrong input! TRY AGAIN!!" << endl;
        if(game.control() == 1)
            control = 1;
    }
    
    return 0;
}
