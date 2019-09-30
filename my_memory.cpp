#include "my_memory.h"

template<typename T>
my_unique_ptr<T>::my_unique_ptr(): ptr_(nullptr), counter_(0){}

template<typename T>
my_unique_ptr<T>::my_unique_ptr(T *obj): ptr_(obj), counter_(1){}

template<typename T>
my_unique_ptr<T>::~my_unique_ptr(){
    delete ptr_;
}

template<typename T>
my_unique_ptr<T>::my_unique_ptr(my_unique_ptr<T> && smart_ptr):ptr_(std::move(smart_ptr.ptr_)), counter_(1){
    smart_ptr.counter_--;
    smart_ptr.ptr_ = nullptr;
}

template<typename T>
bool my_unique_ptr<T>::isNullptr(){
    if(ptr_ == nullptr)
        return true;
    else
        return false;
    
}

template<typename T>
T my_unique_ptr<T>::operator*(){
    return *ptr_;
}

template<typename T>
T* my_unique_ptr<T>::operator->(){
    return ptr_;
}

//template<typename T>
//my_unique_ptr<T>::