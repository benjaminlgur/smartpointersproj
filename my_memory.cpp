#include "my_memory.h"

//Unique pointer area.

template<typename T>
my_unique_ptr<T>::my_unique_ptr(): ptr_(nullptr){}

template<typename T>
my_unique_ptr<T>::my_unique_ptr(T *obj): ptr_(obj){}

template<typename T>
my_unique_ptr<T>::~my_unique_ptr(){
    delete ptr_;
}

template<typename T>
my_unique_ptr<T>::my_unique_ptr(my_unique_ptr<T> && smart_ptr):ptr_(std::move(smart_ptr.ptr_)){ //move() shoudnt be necciary but put in for safty.
    smart_ptr.ptr_ = nullptr;
}

template<typename T>
bool my_unique_ptr<T>::isNullptr() const{
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

template<typename T>
void my_unique_ptr<T>::operator=(my_unique_ptr && smart_ptr){
    delete ptr_;
    ptr_ = std::move(smart_ptr.ptr_); //move() shouldent be neccicary but put in for safty.
    smart_ptr.ptr_ = nullptr;
}


//Shared Pointer area

template<typename T>
bool my_shared_ptr<T>::isNullptr() const{
    if(ptr_ == nullptr)
        return true;
    else
        return false;
}

template<typename T>
my_shared_ptr<T>::my_shared_ptr(): ptr_(nullptr), counter_(nullptr){
    std::cout << "proof\n";
}

template<typename T>
my_shared_ptr<T>::my_shared_ptr(T* obj): ptr_(obj), counter_(new int {1}){}

template<typename T>
my_shared_ptr<T>::my_shared_ptr(const my_shared_ptr<T> & smartptr) {
    if(smartptr.isNullptr() == false){
        ptr_ = smartptr.ptr_;
        counter_ = smartptr.counter_;
        (*counter_)++;
    }
    else { //case of copying uninitlized shared_ptr
        ptr_ = smartptr.ptr_; //should be nullptr
        counter_ = smartptr.counter_; //should be nullptr
        //not increasing counter as not pointing to anything
    }
}

template<typename T>
my_shared_ptr<T>::my_shared_ptr(my_shared_ptr<T> && smart_ptr): ptr_(std::move(smart_ptr.ptr_)), counter_(std::move(smart_ptr.counter_)){ //move() shouldnt be neccesary but put in for safty.
    smart_ptr.ptr_ = nullptr;
    smart_ptr.counter_ = nullptr;
    //dont need to touch counter_ as count does not change in any case.
}

template<typename T>
my_shared_ptr<T>::~my_shared_ptr(){
    if(isNullptr()){ //comparison on nullptr leads to segfaul this is provenative.
        return;
    }
    if((*counter_) == 1){
        delete ptr_;
        delete counter_;
    }
    else {
        ptr_ = nullptr;
        (*counter_)--;
        counter_ = nullptr;
    }
}

template<typename T>
T my_shared_ptr<T>::operator*(){
    return *ptr_;
}

template<typename T>
T* my_shared_ptr<T>::operator->(){
    return ptr_;
}

template<typename T>
void my_shared_ptr<T>::operator=(const my_shared_ptr<T> & smart_ptr){
    if(smart_ptr.isNullptr()){
       clear(); 
       //return
    }
    else {
        clear();
        ptr_ = smart_ptr.ptr_;
        counter_ = smart_ptr.counter_;
        (*counter_)++; //another shared pointer points to the same object so count is increased.
    }
}

template<typename T>
void my_shared_ptr<T>::operator=(my_shared_ptr<T> && smart_ptr){
    if(smart_ptr.isNullptr()){ //case of RHS nullptr
        clear();
    }
    else {
        clear();
        //move() shouldnt be necciary but put in for safty. 
        ptr_ = std::move(smart_ptr.ptr_);
        counter_ = std::move(smart_ptr.ptr_);
        //do not need to modify counter as count will be the same.
    }
}


template<typename T>
void my_shared_ptr<T>::clear(){
        if(isNullptr()){ //comparison on nullptr leads to segfaul this is provenative.
        return;
    }
    if((*counter_) == 1){
        delete ptr_;
        delete counter_;
    }
    else {
        ptr_ = nullptr;
        (*counter_)--;
        counter_ = nullptr;
    }
}