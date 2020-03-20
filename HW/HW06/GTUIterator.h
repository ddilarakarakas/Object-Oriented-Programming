#ifndef GTUIterator_h
#define GTUIterator_h
#include <memory>
#include <exception>
#include <iostream>
using namespace std;

namespace dilaraSTL {
    template <typename T>
    class GTUIterator{
    public:
        GTUIterator()noexcept;
        GTUIterator(T *)noexcept;
        T& operator*()noexcept;
        T*operator->()noexcept;
        GTUIterator& operator++()noexcept;
        GTUIterator& operator--()noexcept;
        bool operator==(const GTUIterator &)noexcept;
        bool operator!=(const GTUIterator &)noexcept;
        GTUIterator& operator=(const GTUIterator &)noexcept;
        T* getterData()noexcept;
    private:
        T* data;
    };
}

#endif /* GTUIterator_h */
