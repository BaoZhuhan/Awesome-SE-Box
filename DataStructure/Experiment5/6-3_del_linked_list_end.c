#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct LNode {
    ElemType data;
    struct LNode* next;
}LNode, * LinkList;
LinkList Create();
void print( LinkList L );
void deletetail( LinkList L );
int main() {

    LinkList L = Create();
    print( L );
    printf( "\n" );
    deletetail( L );
    print( L );
    return 0;
}
LinkList Create() {
    LinkList L, p, s;
    ElemType e;
    L = (LinkList)malloc( sizeof( LNode ) );
    p = L;
    scanf( "%d", &e );
    while (e != -1) {
        s = (LinkList)malloc( sizeof( LNode ) );
        s->data = e;
        p->next = s;
        p = s;
        scanf( "%d", &e );
    }
    p->next = NULL;
    return L;
}
void print( LinkList L ) {
    LinkList p;
    p = L->next;
    while (p) {
        printf( "%d ", p->data );
        p = p->next;
    }
}
/* 请在这里填写答案 */


void deletetail( LinkList L ) {
    LinkList p = L;
    if (p->next == NULL) {
        return;
    } else if (p->next->next == NULL) {
        p->next = NULL;
        return;
    } else {
        while (p->next->next != NULL) {
            p = p->next;
        }
        p->next = NULL;
    }
    return;
}