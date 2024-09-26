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

void AddSMatrix(LMartix M1, LMartix M2, LMartix* M){
    int k = 0;
    TripleNode* p1, * p2, * p, * newptr;
    for(int i = 0; i <= MAXRC; i++){
        M->rhead[i] = NULL;
    }
    M->mu = M1.mu;
    M->nu = M1.nu;
    M->tu = 0;
    if(M1.tu == 0 && M2.tu == 0){ return; }
    for(int i = 1; i <= M1.mu; i++){
        p1 = M1.rhead[i];
        p2 = M2.rhead[i];
        p = NULL;

        while(p1 != NULL && p2 != NULL){
            if(p1->j < p2->j){
                newptr = (TripleNode*)malloc(sizeof(TripleNode));
                *newptr = *p1;
                p1 = p1->next;
            }
            else if(p1->j > p2->j){
                newptr = (TripleNode*)malloc(sizeof(TripleNode));
                *newptr = *p2;
                p2 = p2->next;
            }
            else if(p1->e + p2->e == 0){
                p1 = p1->next;
                p2 = p2->next;
                continue;
            }
            else{
                newptr = (TripleNode*)malloc(sizeof(TripleNode));
                *newptr = *p1;
                newptr->e += p2->e;
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        newptr->next = NULL;
        if(p == NULL) M->rhead[i] = newptr;
        else p->next = newptr;
        p = newptr;
        k++;
    }
    while(p1 != NULL){
                                    
    }
}
