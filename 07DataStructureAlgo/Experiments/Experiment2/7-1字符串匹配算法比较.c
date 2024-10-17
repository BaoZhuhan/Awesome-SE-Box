#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int* get_pi(char* s, int len){
    int* pi = (int*)malloc(len * sizeof(int));

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

void kmp(char* s, char* pattern, int slen, int patternlen){
    char* m = (char*)malloc(1100010 * sizeof(char));

    strcpy(m, pattern);
    m[patternlen] = '#';
    strcpy(m + patternlen + 1, s);
    int len = strlen(m);

    int* pi = get_pi(m, len);

    for(int i = patternlen; i < len; i++){
        if(pi[i] == patternlen){
            printf("%s", s + i - 2 * patternlen);
            free(pi);
            free(m);
            return;
        }
    }

    printf("Not Found");
    free(pi);
    free(m);
    return;
}

int main(){
    char* s = (char*)malloc(1000005 * sizeof(char));

    fgets(s, 1000005, stdin);
    s[strcspn(s, "\n")] = '\0';

    int slen = strlen(s);


    int t;

    scanf("%d", &t);
    getchar();

    while(t--){
        char* pattern = (char*)malloc(100005 * sizeof(char));
        fgets(pattern, 100005, stdin);
        pattern[strcspn(pattern, "\n")] = '\0';
        int patternlen = strlen(pattern);
        kmp(s, pattern, slen, patternlen);
        if(t != 0) printf("\n");
        free(pattern);
    }
    free(s);
    return 0;
}