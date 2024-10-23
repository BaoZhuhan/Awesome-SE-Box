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

typedef struct AVLNode node;

/* 手写工具集 */
int Max(int a, int b){ return a > b ? a : b; }
int Height(AVLTree T){ return T == NULL ? 0 : T->Height; }
int GetBalance(AVLTree T){ return T == NULL ? 0 : Height(T->Left) - Height(T->Right); }

AVLTree LeftRotation(AVLTree A){
    AVLTree B = A->Left;
    A->Left = B->Right;
    B->Right = A;
    A->Height = 1 + Max(Height(A->Left), Height(A->Right));
    B->Height = 1 + Max(Height(B->Left), Height(B->Right));
    return B;
}

AVLTree RightRotation(AVLTree B){
    AVLTree A = B->Right;
    B->Right = A->Left;
    A->Left = B;
    A->Height = 1 + Max(Height(A->Left), Height(A->Right));
    B->Height = 1 + Max(Height(B->Left), Height(B->Right));
    return A;
}

AVLTree LRRotation(AVLTree A){
    A->Left = RightRotation(A->Left);
    return LeftRotation(A);
}

AVLTree RLRotation(AVLTree B){
    B->Right = LeftRotation(B->Right);
    return RightRotation(B);
}

AVLTree Init(int Key){
    AVLTree T = (AVLTree)malloc(sizeof(struct AVLNode));
    T->Key = Key;
    T->Height = 1;
    T->Left = T->Right = NULL;
    return T;
}

AVLTree Insert(AVLTree T, int Key){
    if(T == NULL) T = Init(Key);

    else if(Key < T->Key){
        T->Left = Insert(T->Left, Key);
        if(GetBalance(T) == 2){
            if(Key < T->Left->Key) T = LeftRotation(T);
            else T = LRRotation(T);
        }
    }

    else if(Key > T->Key){
        T->Right = Insert(T->Right, Key);
        if(GetBalance(T) == -2){
            if(Key > T->Right->Key) T = RightRotation(T);
            else T = RLRotation(T);
        }
    }

    T->Height = 1 + Max(Height(T->Left), Height(T->Right));
    return T;
}
