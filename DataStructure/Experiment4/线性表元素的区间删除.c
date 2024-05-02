#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 20
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(){
    printf("\nrun to ri\n");
    int n ;
    scanf("%d" , &n);

    List L;
    L = (List)malloc(n * sizeof(struct LNode));
    L->Last = -1;

    for(int i = 0 ; i < n ; i++){
        scanf("%d" , &L->Data[i]);
        L->Last++;
    }

    return L;
}

void PrintList( List L ){
    printf("\nrun to prl\n");
    for(int i = 0 ; i < L->Last ; i++){
        printf("%d ", L->Data[i] );
    }
    printf("%d\n" ,L->Data[L->Last]);
}

List Delete( List L, ElementType minD, ElementType maxD );

int main()
{
    List L;
    ElementType minD, maxD;
    int i;

    L = ReadInput();
    PrintList( L );
    scanf("%d %d", &minD, &maxD);
    
    L = Delete( L, minD, maxD );
    PrintList( L );

    return 0;
}


int del(List L , Position p){
    // printf("\nrun to del->del %d at %d\n",L->Data[p] , p);
    // printf("L->last-->%d\n" , L->Last);

    if(p < 0 || p > L->Last) return 0;

    for(int i = p ; i <= L->Last ; i++ ){
        L->Data[i] = L->Data[i + 1];
    }
    L->Last--;

    // PrintList( L );
    return 1;
}   

List Delete( List L, ElementType minD, ElementType maxD ){
    int flag = 0;
    while(flag == 0){
        for(int i = 0 ; i <= L->Last ; i++){
            if(L->Data[i] > minD && L->Data[i] < maxD ){ del(L , i);}
        }
        flag = 1;
        for(int i = 0 ; i <= L->Last ; i++){
            if(L->Data[i] > minD && L->Data[i] < maxD ){ flag = 0;}
        }
    }

    return L;
}