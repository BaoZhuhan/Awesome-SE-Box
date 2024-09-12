#include <stdio.h>
#include <stdlib.h>

#define ERROR -1

typedef struct node {
    int* data;
    int front, rear; // define front->NULL
    int size;
}queue;

queue* init( int size ) {
    queue* q = (queue*)malloc( sizeof( queue ) );
    q->data = (int*)malloc( sizeof( int ) );
    q->front = q->rear = 0;
    q->size = size;
    return q;
}

bool isFull( queue* q ) {
    return ((q->rear + 1) % q->size == q->front);
}

bool push( queue* q, int x ) {
    if (isFull( q )) {
        return 0;
    } else {
        q->rear = (q->rear + 1) % q->size;
        q->data[q->rear] = x;
        return 1;
    }
}

bool empty( queue* q ) {
    return (q->front == q->rear);
}

int pop( queue* q ) {
    if (empty( q )) {
        return ERROR;
    } else {
        q->front = (q->front + 1) % q->size;
        return q->data[q->front];
    }
}