#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef struct inputdata {
    int add;
    int index;
    int nxt;
} inputdata;

typedef struct node {
    int index;
    int add;
    int nxt;
    struct node* next;
}node;

int size_a = 0;

inputdata* get_data() {
    int head, n;
    scanf( "%d%d", &head, &n );

    inputdata* a = NULL;
    a = (inputdata*)malloc( n * sizeof( struct inputdata ) );

    for (int i = 0; i < n; i++) {
        scanf( "%d%d%d", &a[i].add, &a[i].index, &a[i].nxt );
    }

    inputdata* b = NULL; //array b to temp store
    b = (inputdata*)malloc( n * sizeof( struct inputdata ) );

    //fill the array b in linked order;
    int pnext = head;
    int cnt = 0;
    while (pnext != -1) {
        for (int i = 0; i < n; i++) {
            if (a[i].add == pnext) {
                b[cnt] = a[i];
                cnt++;
                pnext = a[i].nxt;
                break;
            }
        }
    }

    free( a );
    a = NULL;

    size_a = n;

    return b;
}

node* init() {
    node* H;
    H = (node*)malloc( sizeof( struct node ) );
    H->next = NULL;
    H->nxt = -1;

    return H;
}

node* createNode( node* pre, inputdata data ) {
    node* now;
    now = (node*)malloc( sizeof( struct node ) );

    now->add = data.add;
    now->index = data.index;
    now->next = NULL;
    now->nxt = -1;

    pre->next = now;
    pre->nxt = now->add;

    return now;
}

void arrToList( inputdata* a, node* H ) {
    int ph = 0, pe = size_a - 1, fp = 1; // ph:loc from head ; pe : loc from end ; fp : flag of loc , 1 mean end , 0 mean head;
    node* pnode = H; // loc of linked list

    for (int i = 0; i < size_a; i++) {
        fp = (i % 2 == 0) ? 1 : 0;

        if (fp == 0) {
            pnode = createNode( pnode, a[ph] );
            ph++;
        } else if (fp == 1) {
            pnode = createNode( pnode, a[pe] );
            pe--;
        }
    }

    return;

}

void print( node* H ) {
    node* p = H;
    for (int i = 0; p != NULL; i++) {
        if (i != 0) {
            if (p->nxt != -1) {
                printf( "%05d %d %05d\n", p->add, p->index, p->nxt );
            } else {
                printf( "%05d %d -1", p->add, p->index );
            }

        }
        p = p->next;
    }
}

void debug( int choice, inputdata* a1 ) {
    if (choice == 1) {
        printf( "fun:debug-->choice:1\n" );
        for (int i = 0; i < size_a; i++) {
            printf( "%05d %d %05d\n", a1[i].add, a1[i].index, a1[i].nxt );
        }
        return;
    }
}

int main() {
    inputdata* a = get_data();

    node* H = init();

    arrToList( a, H );
    print( H );
    return 0;
}