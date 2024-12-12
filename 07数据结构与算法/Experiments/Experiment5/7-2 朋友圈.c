#include <stdio.h>
#include <stdlib.h>

#define int long long

int N, M;
int *dsu;
int *friends;

int getRoot(int index) {
    return dsu[index] == index ? index : getRoot(dsu[index]);
}

void merge(int a, int b) {
    dsu[b] = getRoot(a);
}

void initDSU() {
    dsu = (int *)malloc((N + 1) * sizeof(int));
    for (int i = 0; i < N + 1; i++)
        dsu[i] = i;
}

void buildClub() {
    int n, root;
    scanf("%d", &n);
    if (n == 0)
        return;
    scanf("%d", &root);

    int temp;
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &temp);
        dsu[temp] = getRoot(root);
    }
}

void printBig() {
    friends = (int *)malloc((N + 1) * sizeof(int));
    int res = 0;
    for (int i = 0; i < N + 1; i++) {
        dsu[i] = getRoot(i);
        friends[dsu[i]] += 1;
        if (friends[dsu[i]] > res)
            res = friends[dsu[i]];
    }
    printf("%d\n", res);
}

signed main() {
    scanf("%d %d", &N, &M);

    initDSU();

    for (int i = 0; i < M; i++) {
        buildClub();
    }

    printBig();

    free(dsu);
    free(friends);

    return 0;
}