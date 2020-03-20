#ifndef GTUContainer_h
#define GTUContainer_h
#include "GTUIterator.h"
#include "GTUIterator.cpp"
#include <iostream>
#include <exception>
#include <memory>
using namespace std;

namespace dilaraSTL {
    template<typename T>
    class GTUContainer{
    public:
        GTUContainer();
        virtual bool empty()const noexcept = 0;
        virtual int size()const noexcept = 0;
        virtual int max_size()const noexcept = 0;
        virtual void insert(const T&) noexcept(false) = 0;
        virtual void erase(const T&) noexcept = 0;
        virtual void clear() noexcept = 0;
        virtual GTUIterator<T> begin() const noexcept = 0;
        virtual GTUIterator<T> end() const noexcept = 0;
    protected:
        shared_ptr<T> data;
        int used_size;
        int capacity;
    };
    template<typename T>i
    GTUIterator<T> find(GTUIterator<T>,GTUIterator<T>,const T&);//Returns an iterator to the first element in the range [first,last) that compares equal to val. If no such element is found, the function returns last.
    template<typename T,class UnaryPredicate>
    GTUIterator<T> find_if(GTUIterator<T>,GTUIterator<T>,UnaryPredicate);//Returns an iterator to the first element in the range [first,last) for which pred returns true. If no such element is found, the function returns last.
    template<typename T,class Function>
    Function for_each(GTUIterator<T>,GTUIterator<T>,Function fn);//Applies function fn to each of the elements in the range [first,last].

}


#endif /* GTUContainer_h */
