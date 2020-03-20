#include "GTUContainer.h"

namespace dilaraSTL {
    template<typename T>
    GTUContainer<T>::GTUContainer(){
        used_size = 0;
        capacity = 5;
    }
    template<typename T>
    GTUIterator<T> find (GTUIterator<T> first, GTUIterator<T> last, const T& value){
        while(first != last){
            if(*first == value)
                return first;
            ++first;
        }
        return last;
    }
    template<typename T,class UnaryPredicate>
    GTUIterator<T> find_if (GTUIterator<T> first, GTUIterator<T> last, UnaryPredicate pred){
        while(first != last){
            if(pred(*first))
                return first;
            ++first;
        }
        return last;
    }
    template<typename T,class Function>
    Function for_each(GTUIterator<T> first, GTUIterator<T> last, Function fof){
        while(first != last){
            fof (*first);
            ++first;
        }
        return fof;
    }
}
