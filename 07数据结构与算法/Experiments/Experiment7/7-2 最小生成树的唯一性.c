#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int pre, to;
    long long weight;
};

long long N, M, ans, choiced;
struct Edge *len;
int *fa;

int cmp(const void *a, const void *b) {
    return (*(struct Edge *)a).weight - (*(struct Edge *)b).weight;
}

int find(int index) {
    return fa[index] == index ? index : (fa[index] = find(fa[index]));
}

void readG() {
    scanf("%lld%lld", &N, &M);
    fa = (int *)malloc((N + 1) * sizeof(int));
    len = (struct Edge *)malloc((M + 1) * sizeof(struct Edge));
    int pre, to, weight;
    for (int i = 1; i <= M; i++) {
        scanf("%d%d%d", &pre, &to, &weight);
        len[i].to = pre;
        len[i].pre = to;
        len[i].weight = weight;
    }
}

void build(int index) {
    ans += len[index].weight;
    fa[find(len[index].pre)] = find(len[index].to);
}

int getSetN() {
    int res = 0;
    for (int i = 1; i <= N; i++) {
        int flag_temp = 0;
        for (int j = 1; j < i; j++) {
            if (fa[i] == fa[j]) {
                flag_temp = 1;
                break;
            }
        }
        if (flag_temp == 0) {
            res++;
        }
    }
    return res;
}

int judgeOnly(int index, int flag_only) {
    if (flag_only == 0)
        return flag_only;
    if (index == N)
        return flag_only;
    if (len[index].weight != len[index + 1].weight)
        return flag_only;
    int judge[4];
    judge[0] = find(len[index].pre);
    judge[1] = find(len[index].to);
    judge[2] = find(len[index + 1].pre);
    judge[3] = find(len[index + 1].to);
    int diff = 0;
    for (int i = 0; i < 4; i++) {
        int flag_temp = 1;
        for (int j = 0; j < i; j++) {
            if (judge[i] == judge[j]) {
                flag_temp = 0;
                break;
            }
        }
        if (flag_temp)
            diff++;
    }
    if (diff > 2)
        return flag_only;
    return 0;
}

int main() {
    // freopen("input.txt", "r", stdin);
    int flag_only = 1;
    int flag_MST = 1;
    readG();
    qsort(len, (M + 1), sizeof(struct Edge), cmp);
    for (int i = 1; i <= N; i++)
        fa[i] = i;
    for (int i = 1; i <= M; i++) {
        if (choiced == N - 1)
            break;
        if (find(len[i].pre) == find(len[i].to)) {
            continue;
        }
        flag_only = judgeOnly(i, flag_only);
        build(i);
        choiced++;
    }
    if (choiced != N - 1)
        flag_MST = 0;
    if (flag_MST) {
        printf("%lld\n", ans);
        if (flag_only)
            printf("Yes\n");
        else
            printf("No\n");
    } else {
        printf("No MST\n");
        printf("%d\n", getSetN());
    }
}