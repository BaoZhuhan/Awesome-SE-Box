#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int address;
    int data;
    int nxt;
    struct Node* next;
} Node;

Node* createNode( int address, int data, int next ) {
    Node* newNode = (Node*)malloc( sizeof( Node ) );
    newNode->address = address;
    newNode->data = data;
    newNode->nxt = next;
    newNode->next = NULL;
    return newNode;
}

Node* findNode( Node* nodes[], int start, int n ) {
    for (int i = 0; i < n; i++) {
        if (nodes[i]->address == start) {
            return nodes[i];
        }
    }
    return NULL;
}

int main() {
    int start, n;
    scanf( "%d %d", &start, &n );
    Node* nodes[n];
    for (int i = 0; i < n; i++) {
        int address, data, next;
        scanf( "%d %d %d", &address, &data, &next );
        nodes[i] = createNode( address, data, next );
    }

    Node* list[n];
    Node* startNode = findNode( nodes, start, n );
    int count = 0;
    while (startNode != NULL) {
        list[count++] = startNode;
        startNode = findNode( nodes, startNode->nxt, n );
    }

    int i = 0, j = count - 1;
    while (i < j) {
        printf( "%05d %d %05d\n", list[j]->address, list[j]->data, list[i]->address );
        if (i + 1 != j) {
            printf( "%05d %d %05d\n", list[i]->address, list[i]->data, list[j - 1]->address );
        } else {
            printf( "%05d %d -1\n", list[i]->address, list[i]->data );
        }
        i++;
        j--;
    }
    if (i == j) {
        printf( "%05d %d -1\n", list[i]->address, list[i]->data );
    }

    return 0;
}