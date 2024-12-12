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