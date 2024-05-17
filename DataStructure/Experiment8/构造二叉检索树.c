#include <stdlib.h>

/*g++ strand*/
#define true 1
#define false 0
#define nullptr ((void*)0)

typedef struct TNode{
    int data;
    struct TNode* left;
    struct TNode* right;
}BinTree;

BinTree* Insert(BinTree* bst, int x){
    if(bst == nullptr){
        bst = (BinTree*)malloc(sizeof(struct TNode));
        bst->data = x;
        bst->left = bst->right = nullptr;
    }
    else{
        if(x <= bst->data){ bst->left = Insert(bst->left, x); }
        else if(x > bst->data){ bst->right = Insert(bst->right, x); } 
    }
    return bst;
}

void PreOrder(BinTree* tree){
    if(tree == nullptr){ return; }

    printf("%d ", tree->data);
    PreOrder(tree->left);
    PreOrder(tree->right);
}

int main(){
    BinTree* tree = (BinTree*)malloc(sizeof(struct TNode));
    tree->left = tree->right = nullptr;

    int data = 0;
    scanf("%d", &data);

    if(data == 0) tree = nullptr;
    else tree->data = data;

    if(data != 0) scanf("%d", &data);
    while(data != 0){
        Insert(tree, data);
        scanf("%d",&data);
    }

    PreOrder(tree);

    return 0;
}