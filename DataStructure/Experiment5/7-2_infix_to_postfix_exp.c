#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

Stack* createStack() {
    Stack* stack = (Stack*)malloc( sizeof( Stack ) );
    stack->top = -1;
    return stack;
}

int isEmpty( Stack* stack ) {
    return stack->top == -1;
}

void push( Stack* stack, char c ) {
    stack->data[++stack->top] = c;
}

char pop( Stack* stack ) {
    return stack->data[stack->top--];
}

char peek( Stack* stack ) {
    return stack->data[stack->top];
}

int precedence( char c ) {
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    else
        return 0;
}

void infixToPostfix( char* infix, char* postfix ) {
    Stack* stack = createStack();
    int index = 0;
    for (int i = 0; i < strlen( infix ); i++) {
        if (infix[i] >= '0' && infix[i] <= '9') {
            while (infix[i] >= '0' && infix[i] <= '9') {
                postfix[index++] = infix[i++];
            }
            postfix[index++] = ' ';
            i--;
        }
        else if (infix[i] == '(') {
            push( stack, infix[i] );
        }
        else if (infix[i] == ')') {
            while (!isEmpty( stack ) && peek( stack ) != '(') {
                postfix[index++] = pop( stack );
                postfix[index++] = ' ';
            }
            pop( stack );
        }
        else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/') {
            while (!isEmpty( stack ) && precedence( infix[i] ) <= precedence( peek( stack ) )) {
                postfix[index++] = pop( stack );
                postfix[index++] = ' ';
            }
            push( stack, infix[i] );
        }
    }
    while (!isEmpty( stack )) {
        postfix[index++] = pop( stack );
        postfix[index++] = ' ';
    }
    postfix[--index] = '\0';
}

int main() {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];
    fgets( infix, MAX_SIZE, stdin );
    infixToPostfix( infix, postfix );
    printf( "%s\n", postfix );
    return 0;
}