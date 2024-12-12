#include <stdio.h>
#include <stdlib.h>

#define CAPACITY (int)1e6

typedef struct Heap {
    int* data;
    int size;
    int capacity;
}Heap;

Heap* InitHeap( int capacity ) {
    Heap* H = (Heap*)malloc( sizeof( Heap ) );
    H->data = (int*)malloc( (capacity+5) * sizeof( int ) );
    H->size = 0;
    H->data[0] = INT_MIN;
    H->capacity = capacity;
    return H;
}

void Add(Heap *H , int x){
    if(H->size == H->capacity){
        printf("FULL SIZE\n");
        return;
    }

    H->data[++H->size] = x;
    
}
int main() {
    int n = 0;
    scanf( "%d", &n );

    Heap* H = InitHeap( CAPACITY );
    while (n--) {
        int op = 0;
        scanf( "%d", &op );

        switch (op) {
        case 1:
            int x;
            scanf( "%d", &x );
            Add( H, x );
            break;
        case 2:
            printf( "%d\n", H->data[1] );
            break;
        case 3:
            Pop( H );
            break;
        default:
            printf( "ERROR INPUT\n" );
            break;
        }
    }

    return 0;
}