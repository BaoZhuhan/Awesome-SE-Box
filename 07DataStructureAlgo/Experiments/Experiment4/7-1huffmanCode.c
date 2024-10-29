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

/* Helper function to initialize CharCode */
CharCode* initCharCode(char ch, const char* code) {
    CharCode* newCode = (CharCode*)malloc(sizeof(CharCode));
    newCode->ch = ch;
    strcpy(newCode->code, code);
    return newCode;
}

/* Comparison function for sorting frequencies */
int compareFreq(const void* a, const void* b) {
    return (*(int*)a) - (*(int*)b);
}

/* Helper function to calculate the minimum path length of Huffman Tree */
int calculateHuffmanLength(int* frequencies, int size) {
    int totalLength = 0;
    qsort(frequencies, size, sizeof(int), compareFreq);

    for (int i = 0; i < size - 1; i++) {
        frequencies[i + 1] += frequencies[i];
        totalLength += frequencies[i + 1];
        
        int j = i + 1;
        while (j < size - 1 && frequencies[j] > frequencies[j + 1]) {
            int temp = frequencies[j];
            frequencies[j] = frequencies[j + 1];
            frequencies[j + 1] = temp;
            j++;
        }
    }
    return totalLength;
}

/* Helper function to check if a set of codes is prefix-free */
int isPrefixFree(CharCode* codes, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (strcmp(codes[i].code, codes[j].code) > 0) {
                CharCode temp = codes[i];
                codes[i] = codes[j];
                codes[j] = temp;
            }
        }
    }

    for (int i = 0; i < size - 1; i++) {
        if (strncmp(codes[i].code, codes[i + 1].code, strlen(codes[i].code)) == 0) {
            return 0;
        }
    }
    return 1;
}

/* Main validation function */
void validateEncodingSets(CharFreq* charFreq, CharCode** encodingSets, int freqSize, int codeSetSize) {
    int* frequencies = (int*)malloc(freqSize * sizeof(int));
    for (int i = 0; i < freqSize; i++) {
        frequencies[i] = charFreq[i].freq;
    }

    int minLength = calculateHuffmanLength(frequencies, freqSize);

    for (int i = 0; i < codeSetSize; i++) {
        int currentLength = 0;

        for (int j = 0; j < freqSize; j++) {
            int freq = charFreq[j].freq;
            int codeLength = strlen(encodingSets[i][j].code);
            currentLength += freq * codeLength;
        }

        if (currentLength == minLength && isPrefixFree(encodingSets[i], freqSize)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    free(frequencies);
}

int main() {
    int N, M;
    scanf("%d", &N);

    CharFreq* charFreq = (CharFreq*)malloc(N * sizeof(CharFreq));
    for (int i = 0; i < N; i++) {
        scanf(" %c %d", &charFreq[i].ch, &charFreq[i].freq);
    }

    scanf("%d", &M);

    CharCode** encodingSets = (CharCode**)malloc(M * sizeof(CharCode*));
    for (int i = 0; i < M; i++) {
        encodingSets[i] = (CharCode*)malloc(N * sizeof(CharCode));
        for (int j = 0; j < N; j++) {
            char ch;
            char code[64];
            scanf(" %c %s", &ch, code);
            encodingSets[i][j] = *initCharCode(ch, code);
        }
    }

    validateEncodingSets(charFreq, encodingSets, N, M);

    for (int i = 0; i < M; i++) {
        free(encodingSets[i]);
    }
    free(encodingSets);
    free(charFreq);

    return 0;
}
