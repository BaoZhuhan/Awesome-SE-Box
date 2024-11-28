#include <stdio.h>
#include <stdlib.h>

int digit(int x) {
    int res = 0;
    while (x != 0) {
        x /= 10;
        res++;
    }
    return res;
}

int getkth(int x, int k) {
    while (k--) {
        x /= 10;
    }
    return x % 10;
}

int cmp(int a, int b, int k) {
    return getkth(a, k) - getkth(b, k);
}

int main() {
    int n;
    int maxDigit = 0;
    scanf("%d", &n);
    int a[1005];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        int tempDigit = digit(a[i]);
        maxDigit = maxDigit > tempDigit ? maxDigit : tempDigit;
    }
    for (int i = 0; i < maxDigit; i++) {
        for (int j = n - 1; j > 0; j--) {
            for (int k = 0; k < j; k++) {
                if (cmp(a[k], a[k + 1], i) > 0) {
                    int temp = a[k];
                    a[k] = a[k + 1];
                    a[k + 1] = temp;
                }
            }
        }
        for (int j = 0; j < n; j++) {
            printf("%d ", a[j]);
        }
        printf("\n");
    }
    return 0;
}