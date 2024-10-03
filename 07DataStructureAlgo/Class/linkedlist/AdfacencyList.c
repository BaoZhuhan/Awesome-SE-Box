#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node* next;
}Node;

typedef struct Graph{
    int numV;
    struct Node** List;
    int isD;
}Graph;