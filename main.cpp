#include <iostream>
#include "AVLnode.h"

int main() {

    AVLnode *root=nullptr;
    for(int i=10, j=0; i>=1; i--, j++){
       insert(root,i,j);
       insert(root,i,j++);
    }

    printf("Max: %d at %d\n", max(root)->key, max(root)->list->first->key);
    printf("Min: %d at %d\n", min(root)->key, min(root)->list->first->key);
    inOrder(root);
    return 0;
}