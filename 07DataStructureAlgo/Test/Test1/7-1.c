#include <stdio.h>
#include <string.h>
#include <ctype.h>

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void findOccurrences(char *A, char *B) {
    int lenA = strlen(A);
    int lenB = strlen(B);
    for (int i = 0; i <= lenA - lenB; i++) {
        if (strncmp(&A[i], B, lenB) == 0) {
            printf("%d\n", i);
        }
    }
}

int main() {
    char A[1000], B[1000];
    
    fgets(A, 1000, stdin);
    fgets(B, 1000, stdin);
    
    A[strcspn(A, "\n")] = 0;
    B[strcspn(B, "\n")] = 0;
    
    toLowerCase(A);
    toLowerCase(B);
    
    findOccurrences(A, B);
    
    return 0;
}