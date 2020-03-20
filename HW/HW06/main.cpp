#include "GTUSet.h"
#include "GTUVector.h"
#include "GTUSet.cpp"
#include "GTUVector.cpp"
#include <iostream>
#include <exception>
#include <memory>
using namespace std;
using dilaraSTL::GTUSet;
using dilaraSTL::GTUVector;

void foo(int &);
bool even(int &);

int main(){
    GTUSet<int> objeSet;
    GTUVector<int> objeVector;
    cout << "********************************************" << endl;
    cout << "GTUSet TEST" << endl;
    objeSet.insert(5);
    objeSet.insert(1);
    objeSet.insert(2);
    objeSet.insert(4);
    objeSet.insert(7);
    for(auto iterator=objeSet.begin();iterator!=objeSet.end();++iterator){
        cout << *iterator << " ";
    }
    cout << endl << "MAX SIZE: " << objeSet.max_size() << "  USER SIZE: " << objeSet.size() << endl;
    objeSet.insert(8);
    objeSet.insert(9);
    for(auto iterator=objeSet.begin();iterator!=objeSet.end();++iterator){
        cout << *iterator << " ";
    }
    cout << endl << "MAX SIZE: " << objeSet.max_size() << "  USER SIZE: " << objeSet.size() << endl;
    try{
        cout << "TRY INSERT 8 AGAIN!" << endl;
        objeSet.insert(8);
    }
    catch(const exception &xcpt){
        cout << xcpt.what() << endl;
    }
    cout << "ERASE : 2" << endl;
    objeSet.erase(2);
    for(auto iterator=objeSet.begin();iterator!=objeSet.end();++iterator){
        cout << *iterator << " ";
    }
    cout << endl << "MAX SIZE: " << objeSet.max_size() << "  USER SIZE: " << objeSet.size() << endl;
    cout << "CLEAR " << endl;
    objeSet.clear();
    for(auto iterator=objeSet.begin();iterator!=objeSet.end();++iterator){
        cout << *iterator << " ";
    }
    cout << endl << "MAX SIZE: " << objeSet.max_size() << "  USER SIZE: " << objeSet.size() << endl;
    cout << "********************************************" << endl;
    cout << "GTUVector TEST" << endl;
    objeVector.insert(3);
    objeVector.insert(2);
    objeVector.insert(4);
    objeVector.insert(3);
    objeVector.insert(7);
    for(auto iter=objeVector.begin();iter!=objeVector.end();++iter)
        cout << *iter << " ";
    cout << endl << "MAX SIZE: " << objeVector.max_size() << "  USER SIZE: " << objeVector.size() << endl;
    objeVector.insert(6);
    objeVector.insert(1);
    for(auto iter=objeVector.begin();iter!=objeVector.end();++iter)
        cout << *iter << " ";
    cout << endl << "MAX SIZE: " << objeVector.max_size() << "  USER SIZE: " << objeVector.size() << endl;
    cout << "ERASE : 2" << endl;
    objeVector.erase(2);
    for(auto iterator=objeVector.begin();iterator!=objeVector.end();++iterator){
        cout << *iterator << " ";
    }
    cout << endl << "MAX SIZE: " << objeVector.max_size() << "  USER SIZE: " << objeVector.size() << endl;
    cout << "Operator overload [] TEST" << endl;
    cout << "objeVector[2] = " << objeVector[2] << endl;
    cout << "Clear TEST " << endl;
    objeVector.clear();
    for(auto iterator=objeVector.begin();iterator!=objeVector.end();++iterator){
        cout << *iterator << " ";
    }
    cout << endl << "MAX SIZE: " << objeVector.max_size() << "  USER SIZE: " << objeVector.size() << endl;
    cout << "********************************************" << endl;
    cout << "Global Function(find - find_if - for_each) TEST" << endl;
    objeVector.insert(3);
    objeVector.insert(1);
    objeVector.insert(4);
    objeVector.insert(3);
    for(auto iter=objeVector.begin();iter!=objeVector.end();++iter)
        cout << *iter << " ";
    cout << endl << "MAX SIZE: " << objeVector.max_size() << "  USER SIZE: " << objeVector.size() << endl;
    cout << "Find Fuction Test" << endl;
    cout << *find(objeVector.begin(), objeVector.end(), 8) << endl;
    cout << *find(objeVector.begin(), objeVector.end(), 3) << endl;
    cout << "Find_if Fuction Test" << endl;
    cout << *find_if(objeVector.begin(), objeVector.end(), even) << endl;
    cout << "For_each Function Test" << endl;
    for_each(objeVector.begin(), objeVector.end(), foo);
    for(auto iter=objeVector.begin();iter!=objeVector.end();++iter)
        cout << *iter << " ";
    cout << endl << "MAX SIZE: " << objeVector.max_size() << "  USER SIZE: " << objeVector.size() << endl;
    return 0;
}

void foo(int &num){
    num = num * 3;
}

bool even(int &num){
    return num % 2 == 0;
}
