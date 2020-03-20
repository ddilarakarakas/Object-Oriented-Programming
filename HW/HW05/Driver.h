#ifndef Driver_h
#define Driver_h
#include "BoardArray2D.h"
#include "BoardArray1D.h"
#include "BoardVector.h"
#include "AbstractBoard.h"
#include <iostream>
using namespace std;

namespace Board {
    class Driver{
    public:
        void testForBoardArray1D();
        void testForBoardArray2D();
        void testForBoardVector();
        void testForGlobalFunction();
    };
}



#endif /* Driver_h */
