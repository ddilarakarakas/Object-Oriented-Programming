#include "GTUIteratorConst.h"
#include <iostream>
#include <memory>
#include <exception>
using namespace std;

namespace dilaraSTL{
    template <typename T>
    GTUIteratorConst<T>::GTUIteratorConst()noexcept{
        data = new T;
    }
    template <typename T>
    GTUIteratorConst<T>::GTUIteratorConst(T *variable)noexcept{
        data = new T;
        data = variable;
    }
    template <typename T>
    T& GTUIteratorConst<T>::operator*()const noexcept{
        return *data;
    }
    template <typename T>
    T* GTUIteratorConst<T>::operator->()const noexcept{
        return data;
    }
    template <typename T>
    GTUIteratorConst<T>& GTUIteratorConst<T>::operator++()noexcept{
        data++;
        return *this;
    }
    template <typename T>
    GTUIteratorConst<T>& GTUIteratorConst<T>::operator--()noexcept{
        data--;
        return *this;
    }
    template <typename T>
    bool GTUIteratorConst<T>::operator==(const GTUIteratorConst& obje)const noexcept{
        return this->data == obje.data;
    }
    template <typename T>
    bool GTUIteratorConst<T>::operator!=(const GTUIteratorConst& obje)const noexcept{
        return this->data != obje.data;
    }
    template <typename T>
    GTUIteratorConst<T>& GTUIteratorConst<T>::operator=(const GTUIteratorConst& obje)noexcept{
        data = obje.data;
        return *this;
    }
    template <typename T>
    T* GTUIteratorConst<T>::getterData()const{
        return data;
    }
}
