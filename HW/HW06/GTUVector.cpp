#include "GTUVector.h"
#include <iostream>
#include <exception>
#include <memory>
using namespace std;

namespace dilaraSTL {
    template<typename T>
    GTUVector<T>::GTUVector():GTUContainer<T>(){
        shared_ptr<T> temp(new T[this->capacity]);
        this->data = temp;
    }
    template<typename T>
    bool GTUVector<T>::empty()const noexcept{
        if(this->used_size == 0)
            return true;
        else
            return false;
    }
    template<typename T>
    int GTUVector<T>::size()const noexcept{
        return this->used_size;
    }
    template<typename T>
    int GTUVector<T>::max_size()const noexcept{
        return this->capacity;
    }
    template<typename T>
    void GTUVector<T>::insert(const T &obje)noexcept{
        if(this->size() < this->max_size()){
            *(this->end()) = obje;
        }
        if(this->size() >= this->max_size()){
            this->capacity = this->capacity * 2;
            shared_ptr<T> temp(new T[this->capacity]);
            int i = 0;
            for(auto temp_ıter = this->begin();temp_ıter != this->end();++temp_ıter){
                temp.get()[i] = *temp_ıter;
                i++;
            }
            this->data = nullptr;
            this->data = temp;
            *(this->end()) = obje;
        }
        this->used_size++;
    }
    template<typename T>
    void GTUVector<T>::erase(const T &obje)noexcept{
        bool control = false;
        for(auto iter=this->begin();iter!=this->end();++iter){
            if(*(iter) == obje){
                for(auto iter2=iter;iter2!=this->end();++iter2){
                    *(iter2) = *(iter2.getterData()+1);
                    control = true;
                }
                break;
            }
        }
        if(control)
            this->used_size--;
    }
    template<typename T>
    void GTUVector<T>::clear()noexcept{
        this->used_size = 0;
        this->capacity = 1;
        shared_ptr<T> temp(new T[this->capacity]);
        this->data = temp;
    }
    template<typename T>
    GTUIterator<T> GTUVector<T>::begin()const noexcept{
        return (this->data).get();
    }
    template<typename T>
    GTUIterator<T> GTUVector<T>::end()const noexcept{
        return (this->data).get() + this->used_size;
    }
    template<typename T>
    T GTUVector<T>::operator[](int num)noexcept{
        int i = 0;
        GTUIterator<T> p ;
        for(p=this->begin();i<num;++i,++p);
        return *p;
    }
}
