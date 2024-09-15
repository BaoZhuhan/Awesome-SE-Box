#include <stdio.h>
#include <stdlib.h>

const int MAX_SIZE = 1024;

void lower(char* chr) {
    for (int i = 0; chr[i] != '\0'; i++) {
        if (chr[i] >= 'A' && chr[i] <= 'Z') {
            chr[i] = chr[i] - 'A' + 'a';
        }
    }
}

int* init_next(char* tar, int len) {
    int* next = (int*)malloc(len * sizeof(int));
    next[0] = 0;
    int prefix_len = 0, i = 1;

    while (i < len) {
        if (tar[i] == tar[prefix_len]) {
            prefix_len++;
            next[i] = prefix_len;
            i++;
        } else {
            if (prefix_len != 0) {
                prefix_len = next[prefix_len - 1];
            } else {
                next[i] = 0;
                i++;
            }
        }
    }

    return next;
}

void kmp_search() {
    char* src = (char*)malloc(MAX_SIZE * sizeof(char));
    char* tar = (char*)malloc(MAX_SIZE * sizeof(char));

    fgets(src, MAX_SIZE, stdin);
    fgets(tar, MAX_SIZE, stdin);

    int srclen = 0; for (; src[srclen] != '\0'; srclen++);
    int tarlen = 0; for (; tar[tarlen] != '\0'; tarlen++);

    lower(src);
    lower(tar);

    int* next = init_next(tar, tarlen);

    int i = 0, j = 0;
    while (i < srclen) {
        if (src[i] == tar[j]) {
            i++;
            j++;
        } else {
            if (j != 0) {
                j = next[j - 1];
            } else {
                i++;
            }
        }

        if (j == tarlen) {
            printf("%d\n", i - j);
            j = next[j - 1];
        }
    }

    free(next);
    free(src);
    free(tar);
}

int main() {
    kmp_search();
    return 0;
}