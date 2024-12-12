#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
typedef int ElementType;
typedef enum { push, pop, end } Operation;
typedef enum { false, true } bool;
typedef int Position;
typedef struct SNode *PtrToSNode;
struct SNode {
    ElementType *Data;  /* 存储元素的数组 */
    Position Top;       /* 栈顶指针       */
    int MaxSize;        /* 堆栈最大容量   */
};
typedef PtrToSNode Stack;

Stack CreateStack( int MaxSize )
{
    Stack S = (Stack)malloc(sizeof(struct SNode));
    S->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
    S->Top = 0;
    S->MaxSize = MaxSize;
    return S;
}

bool Push( Stack S, ElementType X );
ElementType Pop( Stack S );

Operation GetOp();          /* 裁判实现，细节不表 */
void PrintStack( Stack S ); /* 裁判实现，细节不表 */

int main()
{
    ElementType X;
    Stack S;
    int N, done = 0;

    scanf("%d", &N);
    S = CreateStack(N);
    while ( !done ) {
        switch( GetOp() ) {
        case push: 
            scanf("%d", &X);
            Push(S, X);
            break;
        case pop:
            X = Pop(S);
            if ( X!=ERROR ) printf("%d is out\n", X);
            break;
        case end:
            PrintStack(S);
            done = 1;
            break;
        }
    }
    return 0;
}

/*
在栈的顺序存储实现中，另有一种方法是将Top定义为栈顶的上一个位置。请编写程序实现这种定义下堆栈的入栈、出栈操作。如何判断堆栈为空或者满？
注意：如果堆栈已满，Push函数必须输出“Stack Full”并且返回false；如果队列是空的，则Pop函数必须输出“Stack Empty”，并且返回ERROR。
*/
/* 你的代码将被嵌在这里 */

bool Push( Stack S, ElementType X ) {
    if (S->Top == S->MaxSize) {
        printf("Stack Full\n");
        return false;
    }
    S->Data[S->Top++] = X;
    return true;
}

ElementType Pop( Stack S ) {
    if (S->Top == 0) {
        printf("Stack Empty\n");
        return ERROR;
    }
    return S->Data[--S->Top];
}
