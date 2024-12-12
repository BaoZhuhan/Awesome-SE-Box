#include <stdio.h>
#include <stdlib.h>

#define ERROR -1

typedef struct node{
    int *data;
    int top;
    int size;
}stack;

stack* init(int size){
    stack *s = (stack*)malloc(sizeof(stack));
    s->data = (int*)malloc(size * sizeof(int)); 
    s->top = -1;
    s->size = size;
    return s;
}

bool isFull(stack *s){
    return (s->top == s->size-1);
}

bool push(stack *s , int x){
    if(isFull(s)){
        return 0;
    }else{
        s->data[++(s->top)] = x;
        return 1;
    }
}

bool empty(stack *s){
    return (s->top == -1);
}

int pop(stack *s){
    if(empty(s)){
        return ERROR;
    }else{
        return (s->data[(s->top)--]);
    }
}
