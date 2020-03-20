#ifndef GTUIteratorConst_h
#define GTUIteratorConst_h
#include <memory>
#include <exception>
#include <iostream>
using namespace std;

namespace dilaraSTL {
    template <typename T>
    class GTUIteratorConst{
    public:
        GTUIteratorConst()noexcept;
        GTUIteratorConst(T *)noexcept;
        T& operator*()const noexcept;
        T* operator->()const noexcept;
        GTUIteratorConst& operator++()noexcept;
        GTUIteratorConst& operator--()noexcept;
        bool operator==(const GTUIteratorConst &)const noexcept;
        bool operator!=(const GTUIteratorConst &)const noexcept;
        GTUIteratorConst& operator=(const GTUIteratorConst &)noexcept;
        T* getterData()const;
    private:
        T* data;
    };
}

#endif /* GTUIteratorConst_h */
