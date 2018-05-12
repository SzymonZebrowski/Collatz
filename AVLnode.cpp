//
// Created by SR_4 on 10.05.2018.
//
#include "AVLnode.h"
#include <stdio.h>

void RR_Rotate(AVLnode *&root, AVLnode *node) {
    AVLnode *temp=node->right;
    AVLnode *parent=node->up;

    node->right=temp->left;
    if(node->right!=nullptr){
        node->right->up=node;
    }
    temp->left=node;
    temp->up=parent;
    node->up=temp;
    if(parent!=nullptr){
        if(parent->left==node) parent->left==temp;
        else parent->right=temp;
    }
    else root=temp;

    if(temp->bf==-1) {node->bf=temp->bf=0;}
    else{
        node->bf=-1;
        temp->bf=1;
    }
}

void LL_Rotate(AVLnode *&root, AVLnode *node) {
    AVLnode *temp=node->left;
    AVLnode *parent=node->up;

    node->left=temp->right;
    if(node->left!=nullptr){
        node->left->up=node;
    }
    temp->right=node;
    temp->up=parent;
    node->up=temp;
    if(parent!=nullptr){
        if(parent->left==node) parent->left=temp;
        else parent->right=temp;
    }
    else root=temp;

    if(temp->bf==1) {node->bf=temp->bf=0;}
    else{
        node->bf=1;
        temp->bf=-1;
    }
}

void RL_Rotate(AVLnode *&root, AVLnode *node) {
    AVLnode *temp=node->right;
    AVLnode *temp1=temp->left;
    AVLnode *parent=node->up;

    temp->left=temp1->right;
    if(temp->left!=nullptr) temp->left->up=temp;

    node->right=temp1->left;
    if(node->right!=nullptr) node->right->up=node;

    temp1->left=node;
    temp1->right=temp;
    node->up=temp->up=temp1;
    temp1->up=parent;

    if(parent!=nullptr){
        if(parent->left==node) parent->left=temp1;
        else parent->right=temp1;
    }
    else root=temp1;

    if(temp1->bf==-1) node->bf=1; else node->bf=0;
    if(temp1->bf==1) temp->bf=-1; else temp->bf=0;
    temp1->bf=0;
}

void LR_Rotate(AVLnode *&root, AVLnode *node) {
    AVLnode *temp=node->left;
    AVLnode *temp1=temp->right;
    AVLnode *parent=node->up;

    temp->right=temp1->left;
    if(temp->right!=nullptr) temp->right->up=temp;

    node->left=temp1->right;
    if(node->left!=nullptr) node->left->up=node;

    temp1->right=node;
    temp1->left=temp;
    node->up=temp->up=temp1;
    temp1->up=parent;

    if(parent!=nullptr){
        if(parent->left==node) parent->left=temp1;
        else parent->right=temp1;
    }
    else root=temp1;

    if(temp1->bf==1) node->bf=-1; else node->bf=0;
    if(temp1->bf==-1) temp->bf=1; else temp->bf=0;
    temp1->bf=0;
}

void insert(AVLnode *&root, int key, int index){
    AVLnode *node, *parent, *grandparent;
    int pom;
    node=new AVLnode(key);
   // node->left=node->right=node->up=nullptr;
    //node->key=key, node->bf=0;
    //wstawianie węzła
    parent=root;
    if(parent==nullptr) {
        root=node;
        node->counter++;
        //root->list=new List();
        node->list->pushBack(index);
    }
    else{
        while(true){
            if(key==parent->key){
                parent->counter++;
                parent->list->pushBack(index);
                break;
            }
            else if(key<parent->key){
                if(parent->left==nullptr){
                    parent->left=node;
                    node->counter++;
                    //node->list=new List();
                    node->list->pushBack(index);
                    break;
                }
                parent=parent->left;
            }
            else if(key>parent->key){
                if(parent->right==nullptr){
                    parent->right=node;
                    node->counter++;
          //          node->list=new List();
                    node->list->pushBack(index);
                    break;
                }
                parent=parent->right;
            }
        }

    node->up=parent;

    //naprawa drzewa
    if(parent->bf!=0){
        parent->bf=0;
    }
    else {
        if (parent->left == node)
            parent->bf = 1;
        else
            parent->bf = -1;
        grandparent = parent->up;
        pom = 0;
        while (grandparent != nullptr) {
            if (grandparent->bf) {
                pom = 1;
                break;
            }

            if (grandparent->left == parent) grandparent->bf = 1;
            else grandparent->bf = -1;

            parent = grandparent;
            grandparent = grandparent->up;
        }

        if (pom) {
            if (grandparent->bf == 1) {
                if (grandparent->right == parent) grandparent->bf = 0;
                else if (parent->bf == -1) LR_Rotate(root, grandparent);
                else LL_Rotate(root, grandparent);
            } else {
                if (grandparent->left == parent) grandparent->bf = 0;
                else if (parent->bf == 1) RL_Rotate(root, grandparent);
                else RR_Rotate(root, grandparent);
            }
        }
    }
    }
}

void inOrder(AVLnode *node){
    if(node!=nullptr) {
        inOrder(node->left);
       for(int i=0; i<node->counter; i++) printf("%d ", node->key);
        inOrder(node->right);
    }
}

AVLnode* max(AVLnode *root){
    AVLnode *max=root;
    while(max->right!=nullptr)
        max=max->right;

    return max;
}

AVLnode* min(AVLnode *root){
    AVLnode *min=root;
    while(min->left!=nullptr)
        min=min->left;

    return min;
}