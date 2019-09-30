#pragma once

#include<iostream>

template<typename T>
class my_unique_ptr {
public:
    my_unique_ptr(); //constuctor
    my_unique_ptr(T  *obj); //ownership constructor
    ~my_unique_ptr(); //destructor
    my_unique_ptr(const my_unique_ptr & smart_ptr) = delete; //copy constructor
    my_unique_ptr(my_unique_ptr && smart_ptr); //move constructor
    T operator*(); //overload * operator
    T* operator->(); //overload -> operator
    my_unique_ptr & operator=(const my_unique_ptr & smart_ptr) = delete; //copy assigment
    my_unique_ptr & operator=(my_unique_ptr && smart_ptr); //move assigment
    bool isNullptr(); //returns true if pointer points to nullptr else false.
private:
    T* ptr_;
    int counter_;

};

    #include "my_memory.cpp"