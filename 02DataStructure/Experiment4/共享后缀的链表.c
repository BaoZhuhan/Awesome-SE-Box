#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;

typedef struct Node *PtrToNode;
struct Node {
    ElementType Data; /* 存储结点数据 */
    PtrToNode   Next; /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */

void ReadInput( List L1, List L2 ); /* 裁判实现，细节不表 */
void PrintSublist( PtrToNode StartP ); /* 裁判实现，细节不表 */
PtrToNode Suffix( List L1, List L2 );

int main()
{
    List L1, L2;
    PtrToNode P;

    L1 = (List)malloc(sizeof(struct Node));
    L2 = (List)malloc(sizeof(struct Node));
    L1->Next = L2->Next = NULL;
    ReadInput( L1, L2 );
    P = Suffix( L1, L2 );
    PrintSublist( P );

    return 0;
}

//violence search
PtrToNode Suffix( List L1, List L2 ){
    for(List p1 = L1->Next;p1 != NULL;p1 = p1->Next){
        for(List p2 = L2 ; p2 != NULL; p2 = p2->Next){
            if(p2 == p1){
                return p1;
            }   
        }        
    }
    return NULL;
}

//two point diff search

PtrToNode Suffix( List L1, List L2 ){
    int len1 = 0, len2 = 0;
    List p1 = L1, p2 = L2;
    while(p1 != NULL){
        len1++;
        p1 = p1->Next;
    }
    while(p2 != NULL){
        len2++;
        p2 = p2->Next;
    }
    p1 = L1;
    p2 = L2;
    if(len1 > len2){
        for(int i = 0; i < len1 - len2; i++){
            p1 = p1->Next;
        }
    }else{
        for(int i = 0; i < len2 - len1; i++){
            p2 = p2->Next;
        }
    }
    while(p1 != p2){
        p1 = p1->Next;
        p2 = p2->Next;
    }
    return p1;
}