#include <stdlib.h>

typedef struct node{
    struct node* Right;
    struct node* Left;
    int data;
}BinNode;

typedef BinNode* BinTree;

BinTree Find(BinTree BST , int x){
    if(!BST) return NULL;
    if(x > BST->data , x){

    }
}
