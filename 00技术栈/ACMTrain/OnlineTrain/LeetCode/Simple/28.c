#include <stdio.h>

int* pre(char* str, int len){
    int* pi = (int*)malloc(len * sizeof(int));
    pi[0] = 0;
    for(int i = 1; i < len; i++){
        int j = pi[i - 1];
        while(j > 0 && str[i] != str[j]){
            j = pi[j - 1];
        }
        if(str[i] == str[j]){
            j++;
        }
        pi[i] = j;
    }
    return pi;
}

int strStr(char* haystack, char* needle){
    int haystack_len = 0, needle_len = 0;

    while(needle[needle_len] != '\0'){ needle_len++; }
    while(haystack[haystack_len] != '\0'){ haystack_len++; }

    //KMP Algo
    char* str = (char*)malloc(20005 * sizeof(char));

    for(int i = 0; i < needle_len; i++){
        str[i] = needle[i];
    }
    str[needle_len] = '#';
    for(int i = 0; i < haystack_len; i++){
        str[needle_len + 1 + i] = haystack[i];
    }
    str[needle_len + haystack_len + 1] = '\0';

    int* pi = pre(str, needle_len + haystack_len + 1);

    for(int i = needle_len; i < needle_len + haystack_len + 1; i++){
        if(pi[i] == needle_len){
            free(pi);
            free(str);
            return (i - needle_len * 2);
        }
    }

    free(pi);
    free(str);
    return -1;
}