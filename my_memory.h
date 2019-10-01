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
    void operator=(const my_unique_ptr & smart_ptr) = delete; //copy assigment
    void operator=(my_unique_ptr && smart_ptr); //move assigment
    bool isNullptr() const; //returns true if pointer points to nullptr else false.
private:
    T* ptr_;
};

template<typename T>
class my_shared_ptr {
public:
    my_shared_ptr(); //constructor
    my_shared_ptr(T *obj); //set constructor
    my_shared_ptr(const my_shared_ptr & smart_ptr); //copy costructor
    my_shared_ptr(my_shared_ptr && smart_ptr); //move constructor
    ~my_shared_ptr(); //destructor
    T operator*(); //overload * operator
    T* operator->(); //overload -> operator
    void operator=(const my_shared_ptr & smart_ptr); //copy assigment
    void operator=(my_shared_ptr && smart_ptr); //move assigment
    bool isNullptr() const; //returns true if pointer points to nullptr else false.

private:
    T* ptr_;
    int* counter_;
    void clear();
};

    #include "my_memory.cpp"