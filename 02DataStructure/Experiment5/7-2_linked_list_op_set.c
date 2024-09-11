#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
//#include <math.h>

typedef struct node {
    int data;
    struct node* next;
}node;

node* init() {
    node* H;
    H = (node*)malloc( sizeof( node ) );
    H->next = NULL;
    return H;
}

node* insert( node* H, int data ) {
    node* now;
    now = (node*)malloc( sizeof( node ) );
    now->data = data;
    now->next = H->next;

    H->next = now;

    return now;
}

void get_input( node* H ) {
    int data;
    scanf( "%d", &data );

    while (data != -1) {
        insert( H, data );
        scanf( "%d", &data );
    }

    return;

}

void print( node* H ) {
    node* p = H->next;
    while (p != NULL) {
        printf( "%d ", p->data );
        p = p->next;
    }

    return;
}

void destroy( node* H ) {
    node* p1 = H;
    node* p2 = p1->next;

    while (p2 != NULL) {
        free( p1 );
        p1 = p2;
        p2 = p1->next;
    }
    free( p1 );

    return;
}

int main() {
    node* H = init();
    get_input( H );
    print( H );
    destroy( H );

    return 0;
}