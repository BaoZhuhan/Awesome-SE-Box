#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int i, j; 
    int value;
    struct Node* right, * down;
}OLNode, * OLink;

typedef struct {
    OLink *rhead, *chead;
    int mu, nu ,tu;
}CrossList;
