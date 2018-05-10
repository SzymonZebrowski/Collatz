//
// Created by SR_4 on 10.05.2018.
//

#include "List.h"
#include <stdio.h>

List::List(){
    first= nullptr;
    last= nullptr;
}

void List::pushBack(int key) {
    LISTnode *ln = new LISTnode;
    ln->key=key;
    if(first==nullptr){
        first=ln;
        last=ln;
    }
    else{
        last->next=ln;
        ln->next=nullptr;
        last=ln;
    }
}

void List::popFront(){
    LISTnode *ln=first;
    if(ln==nullptr) return;
    first=first->next;
    delete ln;
}

void List::write(){
    LISTnode *ln=first;
    if(ln==nullptr) {
        printf("Lista pusta!");
        return;
    }
    while(ln!=nullptr){
        printf("%d \n", ln->key);
        ln=ln->next;
    }
}