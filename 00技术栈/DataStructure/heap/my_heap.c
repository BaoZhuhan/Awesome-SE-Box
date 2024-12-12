#include <stdio.h>

/*c++ strand*/
#define nullptr ((void*)0)
#define true 1
#define false 0

#define MAX_SIZE 100

typedef struct MaxHeap {
    int* data;
    int size;
    int capacity;
}MaxHeap;

//search
int Left( MaxHeap* heap, int i ) {
    return 2 * i + 1;
}
int Right( MaxHeap* heap, int i ) {
    return 2 * i + 2;
}
int Parent( MaxHeap* heap, int i ) {
    return(i - 1) / 2;
}

int Peek( MaxHeap* heap ) {
    return heap->data[0];
}

//add
void SiftUp( MaxHeap* heap, int i ) {
    while (true) {
        int parent = Parent( heap, i );
        if (parent < 0 || heap->data[i] <= heap->data[parent]) { break; }

        int temp = heap->data[i];
        heap->data[i] = heap->data[parent];
        heap->data[parent] = temp;
        i = parent;
    }
}

void Push( MaxHeap* heap, int val ) {
    if (heap->size == MAX_SIZE) {
        return;
    }
    heap->data[heap->size++] = val;
    SiftUp( heap, heap->size - 1 );
}

//del
int pop(MaxHeap *heap){
    if(Empty(heap)){
        return __INT_MAX__;
    }
}

