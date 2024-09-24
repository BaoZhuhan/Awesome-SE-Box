#include <stdio.h>

#define MAXRC 1024

typedef struct node{
    int i, j;
    int e;
    struct node* next;
}TripleNode;

typedef struct{
    TripleNode* rhead[MAXRC + 1];
    int mu, nu, tu;
}LMartix;

void createSMatrix(LMartix* M){
    TripleNode* p, * q;
    int row, col, val;
    int i, k = 0;
    for(i = 0; i <= MAXRC; i++){
        M->rhead[i] = NULL;
    }
    scanf("%d%d", &M->nu, &M->nu);
    scanf("%d%d%d", &row, &col, &val);
    while(row != 0){
        k++;
        TripleNode* p = (TripleNode*)malloc(sizeof(TripleNode));
        p->i = row;
        p->j = col;
        p->e = val;
        p->next = NULL;
        q = M->rhead[row];
        if(q == NULL){
            M->rhead[row] = p;
        }
        else{
            while(q->next != NULL){
                q = q->next;
            }
            q->next = p;
        }
        scanf("%d%d%d", &row, &col, &val);
    }
    M->tu = k;
    return;
}