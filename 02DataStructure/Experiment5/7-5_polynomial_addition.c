#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int coe;
    int index;
    struct node *next;
}node;

node* init(){
    node* H;
    H = (node*)malloc(sizeof(node));
    H->next = NULL;
    return H;
}
void read(node *H){
    
}

int main(){
    node *H1 = init();
    node *H2 = init();
    
    read(H1);
    read(H2);
    
    return 0;
}