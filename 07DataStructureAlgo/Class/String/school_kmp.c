#include <stdio.h>

typedef struct node{
    char ch[1024];
    int length;
}SString;

void get_next(SString T, int* next){
    int i = 0;
    int j = 0;
    next[1] = 0;
    while(i < T.length){
        if(j == 0 || T.ch[i] == T.ch[j]){
            ++i;
            ++j;
            next[i] = j;
        }
        else j = next[j];
    }
}