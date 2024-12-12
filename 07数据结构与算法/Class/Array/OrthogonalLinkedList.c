#include <stdio.h>
#include <stdlib.h>

#define ElemType int

typedef struct OLNode{
    int i, j;
    ElemType e;
    struct OlNode* right, * down;
}OLNode, * OLink;

typedef struct{
    OLink* rhead, * chead;
    int mu, nu, tu;
}CrossList;

void CreateSMatrix_OL(CrossList* M){
    OLNode* p, * q;
    int i, j, m, n, t;
    ElemType e;
    scanf("%d%d%d", &m, &n, &t);
    M->mu = m;
    M->nu = n;
    M->tu = t;
    if(!())
}