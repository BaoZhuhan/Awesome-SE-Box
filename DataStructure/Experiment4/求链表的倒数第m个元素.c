#include <stdio.h>
#include <stdlib.h>

#define ERROR -1

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表 */

ElementType Find( List L, int m );

int main()
{
    List L;
    int m;
    L = Read();
    scanf("%d", &m);
    printf("%d\n", Find(L,m));
    Print(L);
    return 0;
}

/* 你的代码将被嵌在这里 */

int length(List L){
    int cot = 0 ;
    List p = L;
    for(int i = 0 ; ; i++){
        if(p->Next != NULL) {
            cot++;
            p = p->Next;
        }else{
            return cot;
        }
    }
}

ElementType vis(List L , int tar){
    int cot = 0 ;
    List p = L;
    for(int i = 0 ; ; i++){
        if(cot != tar) {
            cot++;
            p = p->Next;
        }else{
            return p->Data;
        }
    }
}
ElementType Find( List L, int m ){
    int lent = length(L);

    if(lent < m) return ERROR;
    return vis(L , lent-m+1);
}
