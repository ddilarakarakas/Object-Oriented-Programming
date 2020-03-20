#include "GTUIterator.h"
#include <iostream>
#include <exception>
#include <memory>
using namespace std;

namespace dilaraSTL{
    template <typename T>
    GTUIterator<T>::GTUIterator()noexcept{
        data = new T;
    }
    template <typename T>
    GTUIterator<T>::GTUIterator(T *variable)noexcept{
        data = new T;
        data = variable;
    }
    template <typename T>
    T& GTUIterator<T>::operator*()noexcept{
        return *data;
    }
    template <typename T>
    T* GTUIterator<T>::operator->()noexcept{
        return data;
    }
    template <typename T>
    GTUIterator<T>& GTUIterator<T>::operator++()noexcept{
        data++;
        return *this;
    }
    template <typename T>
    GTUIterator<T>& GTUIterator<T>::operator--()noexcept{
        data--;
        return *this;
    }
    template <typename T>
    bool GTUIterator<T>::operator==(const GTUIterator& obje)noexcept{
        return this->data == obje.data;
    }
    template <typename T>
    bool GTUIterator<T>::operator!=(const GTUIterator& obje)noexcept{
        return this->data != obje.data;
    }
    template <typename T>
    GTUIterator<T>& GTUIterator<T>::operator=(const GTUIterator& obje)noexcept{
        data = obje.data;
        return *this;
    }
    template <typename T>
    T* GTUIterator<T>::getterData()noexcept{
        return data;
    }
}
