#include <stdio.h>
#include <stdlib.h>

#define ERROR -1

typedef struct node {
    int data;
    struct node* next;
}stack;

stack* init() {
    stack* s;
    s = (stack*)malloc( sizeof( stack ) );
    s->next = NULL;
    return s;
}

bool emtpy( stack* s ) {
    return (s->next == NULL);
}

bool push( stack* s, int x ) {
    stack* now;

    now = (stack*)malloc(sizeof(stack));
    now->data = x;
    now->next = s->next;
    s->next = now;
    return 1;
}

bool pop(stack *s){
    stack* now;
    int top;

    if(empty(s)){
        return ERROR;
    }else{
        now = s->next;
        top = now->data;
        s->next = now->next;
        free(now);
        return top; 
    }
}