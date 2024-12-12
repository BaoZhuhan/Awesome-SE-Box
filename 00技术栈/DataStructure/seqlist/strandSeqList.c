#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define N 105

typedef struct elementType {
    
}elementType;

typedef struct lnode{
    elementType data[N];
    int last;
}list;

list *init(){
    list *L;
    L = (list*)malloc(sizeof(list));
    L->last = -1;
    return L;
}

int find(list *L ,elementType x ){
    for(int i = 0 ; i <= L->last ; i++){
        if(L->data[i] == x){
            return i;
        }
    }
    return -1;
}

int insert(list *L , elementType x , int loc){

    if(L->last == N) return 0;
    if(loc < 0 || loc>L->last+1 ) return 0;

    if(loc < L->last+1) {
        for(int j = L->last ; j >= loc; j--){
            L->data[j+1] = L->data[j];
        }
    }
    L->data[loc] = x;
    L->last++;
    return 1;
}

int delete(list *L , int loc){

    if(loc < 0 || loc > L->last ) return 0;

    for(int j = loc ; j < L->last ;j++){
        L->data[j] = L->data[j+1] ;
    }
    L->last--;

    return 1;
}





