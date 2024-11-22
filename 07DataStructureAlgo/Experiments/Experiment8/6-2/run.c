#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *next;

void getNext(char *haystack) {
    next = (int *)malloc(strlen(haystack) * sizeof(int));
    int i = 1;
    int j = 0;
    next[0] = 0;
    for(; i < strlen(haystack) ;i++) {
        if(j == 0 || haystack[i] == haystack[j]) {
            i++;
            j++;
            next[i] = j;
        }else{
            j = next[j];
        }
    }
}