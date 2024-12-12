#include <stdio.h>
#include <string.h>

typedef struct node{
    char ch[1024];
    int length;
}SString;

int next[1024];

// int* my_pre(char* s, int* pi){
//     pi = (int*)malloc(strlen(s) * sizeof(int));
//     pi[0] = 0;
//     int len = strlen(s);

//     for(int i = 1; i < len; i++){
//         int j = pi[i - 1];
//         while(j > 0 && s[i] != s[j]){
//             j = pi[j - 1];
//         }
//         if(s[i] == s[j]) j++;
//         pi[i] = j;
//     }
//     return pi;
// }

void debug(SString s, int* next, int i, int j){
    static int round = -1;
    round++;
    printf("debug round : %d\n", round);
    printf("i = %d , j = %d\n", i, j);
    printf("ch: %s\n", s.ch);
    for(int k = 0; k <= i; k++){
        printf("%d", next[k]);
    }
    printf("\n");
    return;
}

void get_next(SString T, int* next){
    int i = 1;
    int j = 0;
    next[0] = 0;
    next[1] = 0;
    while(i < T.length){
        debug(T, next, i, j);
        if(j == 0 || T.ch[i] == T.ch[j]){
            ++i;
            ++j;
            next[i] = j;
        }
        else j = next[j];
    }
}

int main(){
    SString s;
    // fgets(s.ch, 1024, stdin);
    memcpy(s.ch,"#ABACABAB",9);
    s.length = strlen(s.ch);
    
    get_next(s, next);

    return 0;
}