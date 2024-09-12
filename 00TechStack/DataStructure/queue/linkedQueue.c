#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
typedef struct node {
    int data;
    struct node* next;
}node;

typedef struct node2 {
    node* front, * rear;
    int size;
}queue;

queue* init() {
    queue* q = (queue*)malloc( sizeof( queue ) );
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}

bool empty( queue* q ) {
    return (q->front == NULL);
}

void push( queue* q, int x ) {
    node* now;
    now = (node*)malloc( sizeof( node ) );
    now->data = x;

    if (q->front == NULL) {
        q->front = now;
        q->rear = now;
    }
    else {
        q->rear->next = now;
        q->rear = now;
    }

    q->size++;
}

int pop( queue* q ) {
    node* front;
    int elem;

    if (empty( q )) { return ERROR; }

    front = q->front;

    if (q->front == q->rear) { q->front = q->rear = NULL; }
    else { q->front = q->front->next; }

    elem = front->data;

    free( front );

    return elem;

}
