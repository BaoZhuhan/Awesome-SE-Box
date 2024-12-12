#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSTRLEN 1024

typedef struct node{
    char ch[MAXSTRLEN + 1];
    int length;
}SString;

bool SubString(SString* Sub, SString S, int pos, int len){
    int i;
    if(pos < 1 || len < 0 || pos + len - 1 > S.length){
        printf("ERROR pos or len");
        return false;
    }
    for(i = 1; i <= len;i++){
        Sub->ch[i] = S.ch[pos + i - 1];
    }
    Sub->length = len;
    return true;
}

bool StrInsert(SString* S, int pos, SString* T){
    int i;
    if(pos < 1 || pos > S->length + 1){
        printf("ERROR pos");
        return false;
    }
    if(S->length + T->length > MAXSTRLEN){
        printf("ERROR length");
        return false;
    }
    for(i = S->length; i >= pos; i--){
        S->ch[i + T->length] = S->ch[i];
    }
    for(i = 1; i <= T->length; i++){
        S->ch[pos + i - 1] = T->ch[i];
    }
    S->length = S->length + T->length;
    return true;
}

bool StrDelete(SString* S, int pos, int len){
    int i;
    if(S->length <= 0){
        printf("empty array");
        return false;
    }
    if(pos < 1 || len < 0 || pos + len - 1 > S->length){
        printf("ERROR pos or len");
        return false;
    }
    for(i = pos + len; i <= S->length; i++){
        S->ch[i - len] = S->ch[i];
    }
    S->length = S->length - len;
    return true;
}