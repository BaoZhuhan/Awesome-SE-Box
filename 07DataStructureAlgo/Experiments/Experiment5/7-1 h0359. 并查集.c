#include <stdio.h>
#include <stdlib.h>

int N, T;
int *dsu;

void initDSU() {
    dsu = (int *)malloc((N + 1) * sizeof(int));
    for (int i = 0; i < N + 1; i++) {
        dsu[i] = i;
    }
}

int getRoot(int index) {
    return dsu[index] == index ? index : getRoot(dsu[index]);
}

void merge(int a, int b) {
    dsu[b] = getRoot(a);
}

void find(int a, int b) {
    if (getRoot(a) == getRoot(b)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
}

int main() {
    scanf("%d %d", &N, &T);

    initDSU();

    char op;
    int a, b;
    for (int i = 0; i < T; i++) {
        scanf(" %c %d %d", &op, &a, &b);
        if (op == 'Q') {
            find(a, b);
        }
        if (op == 'M') {
            merge(a, b);
        }
    }

    free(dsu);
    return 0;
}