#include <stdlib.h>

typedef struct node{
    struct node* Right;
    struct node* Left;
    int data;
}BinNode;

typedef BinNode* BinTree;

/*recursion*/
BinTree Find(BinTree BST, int x){
    if(!BST) return NULL;
    if(x > BST->data){
        return Find(BST->Right, x);
    }
    else if(x < BST->data){
        return Find(BST->Left, x);
    }
    else{
        return BST;
    }
}

/*iteration*/
BinTree Find(BinTree BST, int x){
    while(BST){
        if(x > BST->data) BST = BST->Right;
        else if(x < BST->data) BST = BST->Left;
        else break;
    }
    return BST;
}

/*recursion*/
struct node* findMin(struct node* BST){
    if(!BST) return nullptr;
    else if(!BST->Right) return BST;
    else return findMin(BST->Left);
}

/*iteration*/
struct node* findMin(struct node* BST){
    if(BST){
        while(BST->Right){
            BST = BST->Right;
        }
    }
    return BST;
}

struct node* insert(struct node* BST , int x){
    
}