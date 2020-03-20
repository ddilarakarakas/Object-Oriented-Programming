#ifndef GTUVector_h
#define GTUVector_h
#include "GTUContainer.h"
#include <iostream>
using namespace std;

namespace dilaraSTL {
    template<typename T>
    class GTUVector : public GTUContainer<T>{
    public:
        GTUVector();
        bool empty() const noexcept override;
        int size() const noexcept override;
        int max_size() const noexcept override;
        void insert(const T &) noexcept override;
        void erase(const T &) noexcept override;
        void clear() noexcept override;
        GTUIterator<T> begin() const noexcept override;
        GTUIterator<T> end() const noexcept override;
        T operator[](int)noexcept;
    };
}

#endif /* GTUVector_h */
