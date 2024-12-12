#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

int main(){
    char s[1024];
    fgets(s, 1024, stdin);
    int* pi = my_pre(s, pi);

    for(int i = 0; i < strlen(s); i++) printf("%d", pi[i]);
    return 0;
}