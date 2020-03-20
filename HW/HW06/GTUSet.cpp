#include "GTUSet.h"
#include <iostream>
#include <exception>
#include <memory>
using namespace std;

namespace dilaraSTL {
    template<typename T>
    GTUSet<T>::GTUSet():GTUContainer<T>(){
        shared_ptr<T> temp(new T[this->capacity]);
        this->data = temp;
    }
    template<typename T>
    bool GTUSet<T>::empty()const noexcept{
        if(this->used_size == 0)
            return true;
        else
            return false;
    }
    template<typename T>
    int GTUSet<T>::size()const noexcept{
        return this->used_size;
    }
    template<typename T>
    int GTUSet<T>::max_size()const noexcept{
        return this->capacity;
    }
    template<typename T>
    void GTUSet<T>::insert(const T &obje)noexcept(false){
        bool control = true;
        for(auto iteretor = this->begin();iteretor != this->end();++iteretor){
            if(*iteretor == obje){
                throw invalid_argument("Invalid Argument: You CANNOT insert an object in the set!");
                control = false;
            }
        }
        if(control){
            if(this->size() <= this->max_size()){
                *(this->end()) = obje;
            }
            if(this->size() > this->max_size()){
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
    }
    template<typename T>
    void GTUSet<T>::erase(const T &obje)noexcept{
        bool control = false;
        for(auto iter=this->begin();iter!=this->end();++iter){
            if(*(iter) == obje){
                for(auto iter2 = iter; iter2 != this->end(); ++iter2){
                    *(iter2) = *(iter2.getterData()+1);
                    control = true;
                }
            }
        }
        if(control)
            this->used_size--;
    }
    template<typename T>
    void GTUSet<T>::clear()noexcept{
        this->used_size = 0;
        this->capacity = 1;
        shared_ptr<T> temp(new T[this->capacity]);
        this->data = temp;
    }
    template<typename T>
    GTUIterator<T> GTUSet<T>::begin()const noexcept{
        return (this->data).get();
    }
    template<typename T>
    GTUIterator<T> GTUSet<T>::end()const noexcept{
        return (this->data).get() + this->used_size;
    }
    
}
