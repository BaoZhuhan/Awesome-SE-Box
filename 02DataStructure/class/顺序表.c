#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define N 10

typedef struct list {
    elementtype data[N];
    int last ;
}list;

list *MakeEmpty( ){
    list *ptrl;
    ptrl = (list*)malloc(sizeof(list));
    ptrl -> last = -1;
    return ptrl;
} 

list find(elementtype x , list *ptrl){
    int i = 0 ;
    while( i <= ptrl-> last && ptrl->data[i] != x) {i++ ;}

    if(i > ptrl->last) return -1;
    else return i;
}

list 

void run(){

}

int main(){
    int T = 1;
    while(T--) run();
    return 0;
}