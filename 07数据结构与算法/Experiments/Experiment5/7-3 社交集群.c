#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *dsuPeo, *dsuIst, *cot;
int N;

int getRoot(int *dsu, int index) {
    return dsu[index] == index ? index : (dsu[index] = getRoot(dsu, dsu[index]));
}

void merge(int *dsu, int a, int b) {
    dsu[getRoot(dsu, b)] = getRoot(dsu, a);
}

void initDSU() {
    dsuPeo = (int *)malloc((N + 1) * sizeof(int));
    dsuIst = (int *)malloc(1001 * sizeof(int));
    memset(dsuPeo, 0, (N + 1) * sizeof(int));
    for (int i = 0; i <= 1000; i++) {
        dsuIst[i] = i;
    }
}

void buildPeo(int index) {
    int k, root, temp;
    scanf("%d:", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &temp);
        if (i == 0) {
            root = temp;
        } else {
            merge(dsuIst, root, temp);
        }
    }
    dsuPeo[index] = getRoot(dsuIst, root);
}

int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

void getAns() {
    cot = (int *)malloc((N + 1) * sizeof(int));
    memset(cot, 0, (N + 1) * sizeof(int));
    for (int i = 1; i <= N; i++) {
        dsuPeo[i] = getRoot(dsuIst, dsuPeo[i]);
        cot[dsuPeo[i]] += 1;
    }
    qsort(cot, N + 1, sizeof(int), compare);
    int size = 0;
    for (int i = 0; i <= N; i++) {
        if (cot[i] == 0) {
            size = i;
            break;
        }
    }
    printf("%d\n", size);
    for (int i = 0; i < size; i++) {
        if (i > 0)
            printf(" ");
        printf("%d", cot[i]);
    }
    printf("\n");
}

int main() {
    scanf("%d", &N);
    initDSU();
    for (int i = 1; i <= N; i++) {
        buildPeo(i);
    }
    getAns();
    free(dsuIst);
    free(dsuPeo);
    free(cot);
    return 0;
}