#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* my_pre(char* s, int* pi, int len){
    pi = (int*)malloc(strlen(s) * sizeof(int));
    pi[0] = 0;

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
    char t[1024];

    fgets(t, 1024, stdin);
    fgets(s, 1024, stdin);

    s[strcspn(s, "\n")] = 0;
    t[strcspn(t, "\n")] = 0;

    int slen = strlen(s);

    char n[1024];
    strcpy(n, s);
    n[slen] = '#';
    strcpy(n + slen + 1, t);

    int nlen = strlen(n);

    for(int i = 0; i < nlen; i++){
        if(n[i] >= 'a' && n[i] <= 'z'){
            n[i] = n[i] - 'a' + 'A';
        }
    }

    int* pi = my_pre(n, pi, nlen);

    for(int i = slen; i < nlen; i++){
        if(pi[i] == slen){
            printf("%d\n", i - slen - slen);
        }
    }

    // printf("\n%s\n", n);
    // for(int i = 0; i < nlen; i++){
    //     printf("%d", pi[i]);
    // }

    return 0;
}