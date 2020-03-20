#ifndef GTUSet_h
#define GTUSet_h
#include "GTUContainer.h"
#include "GTUContainer.cpp"
#include <iostream>
using namespace std;

namespace dilaraSTL {
    template<typename T>
    class GTUSet : public GTUContainer<T>{
    public:
        GTUSet();
        bool empty() const noexcept override;
        int size() const noexcept override;
        int max_size() const noexcept override;
        void insert(const T &) noexcept(false) override;
        void erase(const T &) noexcept override;
        void clear() noexcept override;
        GTUIterator<T> begin() const noexcept override;
        GTUIterator<T> end() const noexcept override;
    };
}

#endif /* GTUSet_h */



