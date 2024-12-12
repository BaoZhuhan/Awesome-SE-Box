#include <stdio.h>

#define MAXSIZE 1024

typedef struct{
    int i, j;
    int e;
}triple;

typedef struct{
    triple data[MAXSIZE + 1];
    int mu, nu, tu;
}tsmatrix;

void createSMatrix(tsmatrix* m){
    int row, col, val, k = 0;
    scanf("%d%d", &m->mu, &m->nu);
    scanf("%d%d%d", &row, &col, &val);
    while(row != 0){
        k++;
        m->data[k].i = row;
        m->data[k].j = col;
        m->data[k].e = val;
        scanf("%d%d%d", &row, &col, &val);
    }
    m->tu = k;
    return;
}

/*O(nu*tu)*/
void stupidT(tsmatrix m, tsmatrix* t){
    int p, q, col;
    t->mu = m.nu;
    t->nu = m.mu;
    t->tu = m.tu;
    if(t->tu){
        q = 1;
        for(col = 1; col <= m.nu; ++col){
            for(p = 1; p <= m.tu; ++p){
                if(m.data[p].j == col){
                    t->data[q].i = m.data[p].j;
                    t->data[q].j = m.data[p].i;
                    t->data[q].e = m.data[p].e;
                    ++q;
                }
            }
        }
    }
    return;
}

/*O(nu+tu)*/
void fastT(tsmatrix M, tsmatrix* T){
    int col, t, p, q;
    int num[20], cpot[20];
    T->mu = M.nu;
    T->nu = M.mu;
    T->tu = M.tu;

    if(T->tu){
        for(col = 1; col <= M.nu; ++col){
            num[col] = 0;
        }
        for(t = 1; t <= M.tu; ++t){
            num[M.data[t].j]++;
        }
        cpot[1] = 1;
        for(col = 2; col <= M.nu; ++col){
            cpot[col] = cpot[col - 1] + num[col - 1];
        }
        for(p = 1; p <= M.tu; ++p){
            col = M.data[p].j;
            q = cpot[col];
            T->data[q].i = M.data[p].j;
            T->data[q].j = M.data[p].i;
            T->data[q].e = M.data[p].e;
            cpot[col]++;
        }
    }

    return;
}