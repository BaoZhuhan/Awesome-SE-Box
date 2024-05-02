#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
typedef int ElementType;
typedef enum { push, pop, end } Operation;
typedef enum { false, true } bool;
typedef int Position;
typedef struct SNode* PtrToSNode;
struct SNode {
    ElementType* Data;  /* 存储元素的数组 */
    Position Top;       /* 栈顶指针       */
    int MaxSize;        /* 堆栈最大容量   */
};
typedef PtrToSNode Stack;

Stack CreateStack( int MaxSize ) {
    Stack S = (Stack)malloc( sizeof( struct SNode ) );
    S->Data = (ElementType*)malloc( MaxSize * sizeof( ElementType ) );
    S->Top = 0;
    S->MaxSize = MaxSize;
    return S;
}

bool Push( Stack S, ElementType X );
ElementType Pop( Stack S );

Operation GetOp();          /* 裁判实现，细节不表 */
void PrintStack( Stack S ); /* 裁判实现，细节不表 */

int main() {
    ElementType X;
    Stack S;
    int N, done = 0;

    scanf( "%d", &N );
    S = CreateStack( N );
    while (!done) {
        switch (GetOp()) {
        case push:
            scanf( "%d", &X );
            Push( S, X );
            break;
        case pop:
            X = Pop( S );
            if (X != ERROR) printf( "%d is out\n", X );
            break;
        case end:
            PrintStack( S );
            done = 1;
            break;
        }
    }
    return 0;
}

/* 你的代码将被嵌在这里 */

bool Push( Stack S, ElementType X ) {
    if (S->Top == S->MaxSize) {
        printf( "Stack Full\n" );
        return false;
    }

    S->Data[(S->Top)++] = X;
    return true;
}

ElementType Pop( Stack S ) {
    if (S->Top == 0) {
        return ERROR;
        printf( "Stack Empty\n" );
    }

    return S->Data[--(S->Top)];
}