#include <stdio.h>
#include <stdlib.h>

int N, M, choiced, ans;
int fa[105];

struct Edge {
    int weight;
    int to, pre;
};

struct Edge len[1000];

int cmp(const void *a, const void *b) {
    return (*(struct Edge *)a).weight - (*(struct Edge *)b).weight;
}

// union-find disjoint sets
int find(int x) {
    return fa[x] == x ? x : (fa[x] = find(fa[x]));
}

void build(int x) {
    ans += len[x].weight;
    fa[find(len[x].pre)] = find(len[x].to);
}

int main() {
    freopen("input.txt", "r", stdin);
    int x, y, weight;
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= M; i++) {
        scanf("%d%d%d", &x, &y, &weight);
        len[i].to = x;
        len[i].pre = y;
        len[i].weight = weight;
    }
    qsort(len, M, sizeof(struct Edge), cmp);
    for (int i = 1; i <= N; i++)
        fa[i] = i;
    for (int i = 1; i <= M; i++) {
        if (choiced == N - 1)
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