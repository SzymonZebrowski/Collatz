//
// Created by SR_4 on 10.05.2018.
//

#ifndef COLLATZ_LIST_H
#define COLLATZ_LIST_H
#include "ListNode.h"

struct List{
    LISTnode *first;
    LISTnode *last;
    List();
    void pushBack(int key);
    void popFront();
    void write();
};
#endif //COLLATZ_LIST_H
