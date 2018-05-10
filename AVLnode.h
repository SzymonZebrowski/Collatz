//
// Created by SR_4 on 10.05.2018.
//

#ifndef COLLATZ_AVLNODE_H
#define COLLATZ_AVLNODE_H
#include "List.h"

struct AVLnode{
    AVLnode *up;
    AVLnode *left;
    AVLnode *right;
    List *list;
    int key;
    int bf;
    int counter;

    void LL_Rotate(AVLnode *root, AVLnode *node);
    void RR_Rotate(AVLnode *root, AVLnode *node);
    void LR_Rotate(AVLnode *root, AVLnode *node);
    void RL_Rotate(AVLnode *root, AVLnode *node);
    void insert(AVLnode *root, int k);

};
#endif //COLLATZ_AVLNODE_H
