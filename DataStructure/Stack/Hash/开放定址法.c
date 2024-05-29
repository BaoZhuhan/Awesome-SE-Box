#include <stdio.h>
#include <stdlib.h>

#define MAX_TABLE_SIZE 100000
typedef int element_type;
typedef int index;
typedef index position;
typedef enum{ legitimate, empty, deleted } entry_type;

typedef struct HashEntry Cell;
struct HashEntry{
    element_type data;
    entry_type info;
};

typedef struct TableNode* HashTable;
struct TableNode{
    int size;
    Cell* cells;
};

int NextPrime(int n){
    int i, p = (n % 2) ? n + 2 : n + 1;

    while(p <= MAX_TABLE_SIZE){
        for(i = (int)sqrt(p); i > 2; i--){
            if(!(p % i)){ break; }
        }
        if(i == 2){ break; }
        else{ p += 2; }
    }
    return p;
}

HashTable CreateTable(int table_size){
    HashTable H;
    int i;
    H = (HashTable)malloc(sizeof(struct TableNode));
    H->cells = (Cell*)malloc(H->size * sizeof(Cell));
    for(i = 0; i < H->size; i++){
        H->cells[i].info = empty;
    }
    return H;
}

int main(){
    return 0;
}