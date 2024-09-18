#include <stdio.h>

typedef struct node{
    char ch[1024];
    int length;
}SString;

int* my_pre(char* s, int* pi){
    pi = (int*)malloc(strlen(s) * sizeof(int));
    pi[0] = 0;
    int len = strlen(s);

    for(int i = 1; i < len; i++){
        int j = pi[i - 1];
        while(j > 0 && s[i] != s[j]){
            j = pi[j - 1];
        }
        if(s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}


void get_next(SString T, int* next){
    int i = 1;
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