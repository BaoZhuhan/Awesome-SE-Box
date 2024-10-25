here is a program, please ensure that the premise of its original function, change it to my programming style.
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char ch;
    int freq;
} CharFreq;

typedef struct {
    char ch;
    char code[64];
} CharCode;

typedef struct {
    int freq;
    int code_length;
} TreeNode;

int cmp_freq(const void *a, const void *b) {
    return (*(int *)a) - (*(int *)b);
}

int huffman_tree_length(int *frequencies, int N) {
    int total_length = 0;
    qsort(frequencies, N, sizeof(int), cmp_freq);
    
    for (int i = 0; i < N - 1; i++) {
        frequencies[i + 1] += frequencies[i];
        total_length += frequencies[i + 1];
        
        int j = i + 1;
        while (j < N - 1 && frequencies[j] > frequencies[j + 1]) {
            int temp = frequencies[j];
            frequencies[j] = frequencies[j + 1];
            frequencies[j + 1] = temp;
            j++;
        }
    }
    return total_length;
}

int is_prefix_free(CharCode *codes, int N) {
    // Sort codes lexicographically
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (strcmp(codes[i].code, codes[j].code) > 0) {
                CharCode temp = codes[i];
                codes[i] = codes[j];
                codes[j] = temp;
            }
        }
    }
    for (int i = 0; i < N - 1; i++) {
        if (strncmp(codes[i].code, codes[i + 1].code, strlen(codes[i].code)) == 0) {
            return 0;
        }
    }
    return 1;
}

void validate_encoding(CharFreq *char_freq, CharCode **encoding_sets, int N, int M) {
    int frequencies[N];
    for (int i = 0; i < N; i++) {
        frequencies[i] = char_freq[i].freq;
    }

    int min_path_length = huffman_tree_length(frequencies, N);

    for (int i = 0; i < M; i++) {
        int current_path_length = 0;
        
        for (int j = 0; j < N; j++) {
            int freq = char_freq[j].freq;
            int code_length = strlen(encoding_sets[i][j].code);
            current_path_length += freq * code_length;
        }
        
        if (current_path_length == min_path_length && is_prefix_free(encoding_sets[i], N)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
}

int main() {
    int N, M;
    scanf("%d", &N);

    CharFreq char_freq[N];
    for (int i = 0; i < N; i++) {
        scanf(" %c %d", &char_freq[i].ch, &char_freq[i].freq);
    }

    scanf("%d", &M);

    CharCode *encoding_sets[M];
    for (int i = 0; i < M; i++) {
        encoding_sets[i] = (CharCode *)malloc(N * sizeof(CharCode));
        for (int j = 0; j < N; j++) {
            scanf(" %c %s", &encoding_sets[i][j].ch, encoding_sets[i][j].code);
        }
    }

    validate_encoding(char_freq, encoding_sets, N, M);

    for (int i = 0; i < M; i++) {
        free(encoding_sets[i]);
    }

    return 0;
}

```