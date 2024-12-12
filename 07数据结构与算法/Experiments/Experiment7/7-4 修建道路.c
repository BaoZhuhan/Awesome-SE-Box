#include <stdio.h>
#include <stdlib.h>

int N, choiced, ans;
int *fa;

struct Edge {
    int weight;
    int pre, to;
};

struct Edge *len;

int cmp(const void *a, const void *b) {
    return (*(struct Edge *)a).weight - (*(struct Edge *)b).weight;
}

int find(int x) {
    return fa[x] == x ? x : (fa[x] = find(fa[x]));
}

void build(int index) {
    ans += len[index].weight;
    fa[find(len[index].pre)] = find(len[index].to);
}

int main() {
    // freopen("input.txt", "r", stdin);
    scanf("%d", &N);
    fa = (int *)malloc((N + 1) * sizeof(int));
    len = (struct Edge *)malloc((N * N) * sizeof(struct Edge));
    for (int i = 1; i <= N; i++)
        fa[i] = i;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int index = (i - 1) * N + j - 1;
            scanf("%d", &len[index].weight);
            len[index].pre = i;
            len[index].to = j;
        }
    }
    qsort(len, N * N, sizeof(struct Edge), cmp);
    scanf("%d", &choiced);
    for (int i = 0; i < choiced; i++) {
        int pre, to;
        scanf("%d%d", &pre, &to);
        fa[find(pre)] = find(to);
    }
    for (int i = 0; i < N * N; i++) {
        if (choiced >= N - 1)
            break;
        if (find(len[i].pre) == find(len[i].to))
            continue;
        else {
            build(i);
            choiced++;
        }
    }
    printf("%d", ans);
    return 0;
}