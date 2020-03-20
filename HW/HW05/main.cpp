#include <iostream>
#include "BoardArray1D.h"
#include "BoardArray2D.h"
#include "BoardVector.h"
#include "AbstractBoard.h"
#include "Driver.h"
using namespace std;
using namespace Board;

int main(){
    Driver test;
    int control = 0;
    int choice;
    while(control == 0){
        cout << "********************************************" << endl;
        cout << "          ***TEST MENU***" << endl;
        cout << "ENTER THE 1 FOR TEST FOR BOARD ARRAY1D" << endl;
        cout << "ENTER THE 2 TEST FOR BOARD ARRAY2D" << endl;
        cout << "ENTER THE 3 TEST FOR BOARD VECTOR" << endl;
        cout << "ENTER THE 4 TEST FOR GLOBAL FUNCTION" << endl;
        cout << "ENTER THE 5 FOR EXIT" << endl;
        cout << "********************************************" << endl;
        cout << "Choice: ";
        cin >> choice;
        if(choice == 1)
            test.testForBoardArray1D();
        else if(choice == 2)
            test.testForBoardArray2D();
        else if(choice == 3)
            test.testForBoardVector();
        else if (choice == 4)
            test.testForGlobalFunction();
        else if(choice == 5)
            control = 1;
        else
            cout << "Wrong Choice!!!" << endl;
    }
    return 0;
}
