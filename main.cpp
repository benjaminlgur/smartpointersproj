#include <iostream>
#include "my_memory.h"
using namespace std;


void shareDelete(){
    my_shared_ptr<int> t1(new int {5});
    my_shared_ptr<int> t2(t1);
    if(*t2 == 5)
        cout << "test 1 ... OK\n";
    t1.~my_shared_ptr();
    if(t1.isNullptr())
        cout << "test 2 ... OK\n";
    if(*t2 == 5)
        cout << "test 3 ... OK\n";
}

void shareMove(){
    my_shared_ptr<int> t3(new int {8});
    my_shared_ptr<int> t4(move(t3));
    if(*t4 == 8 && t3.isNullptr())
        cout << "test 4 ... OK\n";

}

void shareEqual(){
    my_shared_ptr<int> t5(new int {2});
    my_shared_ptr<int> t6(new int {5});
    t6 = t5;
    if(*t5 == *t6){
        cout << "test 5 ... OK\n";
    }
    my_shared_ptr<int> t7;
    my_shared_ptr<int> t8(t7);
    t7 = t6;
    if(*t7 == *t6){
       cout << "test 6 ... OK\n";
    }
    my_shared_ptr<int> t9(new int {44});
    t5 = move(t9);
    if(*t5 == 44)
        cout << "test 7 ... OK\n";
}

void uniquetest(){
    //my_unique_ptr<int> u1(new int {6});
    //my_unique_ptr<int> u2;
    //u2 = u1;
}


int main(){
    shareDelete();
    shareMove();
    shareEqual();
    //uniquetest();
}