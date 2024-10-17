#include <stdio.h>
#include <stdlib.h>

typedef struct AVLNode* PtrToAVLNode;
struct AVLNode{
    int Key;
    PtrToAVLNode Left;
    PtrToAVLNode Right;
    int Height;
};
typedef PtrToAVLNode AVLTree;

AVLTree Insert(AVLTree T, int Key);
void PostOrderPrint(AVLTree T); /* details omitted */
void InOrderPrint(AVLTree T);   /* details omitted */

int main(){
    int N, Key, i;
    AVLTree T = NULL;

    scanf("%d", &N);
    for(i = 0; i < N; i++){
        scanf("%d", &Key);
        T = Insert(T, Key);
    }
    PostOrderPrint(T);
    InOrderPrint(T);

    return 0;
}
/* Your function will be put here */

/* 手写工具集 */
int max(int a, int b){ return a > b ? a : b; }
int height(AVLTree T){ return T == NULL ? 0 : T->Height; }
int getBalance(AVLTree T){ return T == NULL ? 0 : height(T->Left) - height(T->Right); }

/* 右旋 */
AVLTree rightRotate(AVLTree y){
    AVLTree x = y->Left;
    AVLTree t2 = x->Right;

    x->Right = y;
    y->Left = t2;

    y->Height = max(height(y->Left), height(y->Right)) + 1;
    x->Height = max(height(x->Left), height(x->Right)) + 1;

    return x;
}

/* 左旋 */
AVLTree leftRotate(AVLTree x){
    AVLTree y = x->Right;
    /* ! Test case 4 :base on HACKING */
    // y == NULL ??? 
    AVLTree t2 = y->Left;

    y->Left = x;
    x->Right = t2;

    y->Height = max(height(y->Left), height(y->Right)) + 1;
    x->Height = max(height(x->Left), height(x->Right)) + 1;

    return y;
}

/* 新节点 */
AVLTree init(int value){
    AVLTree T = (AVLTree)malloc(sizeof(struct AVLNode));
    T->Height = 1;
    T->Key = value;
    T->Left = NULL;
    T->Right = NULL;
    return T;
}

AVLTree Insert(AVLTree T, int Key){
    if(T == NULL) return init(Key);

    if(Key < T->Key) T->Left = Insert(T->Left, Key);
    else if(Key > T->Key) T->Right = Insert(T->Right, Key);
    else{
        T->Height = 1 + max(height(T->Left), height(T->Right));
        return T;
    }

    T->Height = 1 + max(height(T->Left), height(T->Right));
    int balance = getBalance(T);

    if(balance > 1 && Key < T->Left->Key) return rightRotate(T);
    if(balance < -1 && Key > T->Right->Key) return leftRotate(T);

    if(balance > 1 && Key > T->Left->Key){
        /* ! Test case 4 :base on HACKING */
        T->Left = leftRotate(T->Left);
        return rightRotate(T);
    }

    if(balance < -1 && Key < T->Right->Key){
        T->Right = rightRotate(T->Right);
        return leftRotate(T);
    }
    return T;
}