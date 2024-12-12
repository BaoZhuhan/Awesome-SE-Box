#include <stdio.h>
#include <stdlib.h>

int **graph;
struct set *sets;
int set_N = 0;
int N, E;
int flag = 1;

struct set {
    int pre;
    int to;
    int weight;
};

void BuildGraph() {
    sets = (struct set *)malloc(N * sizeof(struct set));
    graph = (int **)calloc(N + 1, sizeof(int *));
    for (int i = 1; i <= N; i++) {
        graph[i] = (int *)calloc(N + 1, sizeof(int));
    }

    int pre, to, weight;
    for (int i = 0; i < E; i++) {
        scanf("%d%d%d", &pre, &to, &weight);
        graph[pre][to] = weight;
    }
}

int inDegree(int index) {
    int res = 0;
    for (int i = 1; i <= N; i++) {
        if (graph[i][index] == 1)
            res++;
    }
    return res;
}

int cleanNode(int index) {
    int big_index = 1;
    for (int i = 1; i <= N; i++) {
        big_index = graph[index][i] > graph[index][big_index] ? i : big_index;
    }
    struct set newset;
    newset.pre = index;
    newset.to = big_index;
    newset.weight = graph[index][big_index];
    sets[set_N++] = newset;
    int res = graph[index][big_index];
    for (int i = 1; i <= N; i++) {
        graph[index][i] = 0;
    }
    return res;
}

int topo_sort() {
    int res = 0;
    int cot = 0;
    int *visited = (int *)calloc(N + 1, sizeof(int));
    while (cot != N) {
        int index = -1;
        for (int i = 1; i <= N; i++) {
            if (visited[i] == 0 && inDegree(i) == 0) {
                index = i;
                break;
            }
        }
        if (index == -1)
            break;
        cot++;
        visited[index] = 1;
        res += cleanNode(index);
    }
    if (cot != N)
        flag = 0;
    free(visited);
    return res;
}

int cmp(const void *a, const void *b) {
    if ((*(struct set *)a).pre != (*(struct set *)a).pre) {
        return (*(struct set *)a).pre - (*(struct set *)a).pre;
    } else {
        return (*(struct set *)a).to - (*(struct set *)a).to;
    }
}

int main() {
    scanf("%d%d", &N, &E);
    BuildGraph();
    int res = topo_sort();
    if (flag == 0) {
        printf("unworkable project\n");
    } else {
        printf("%d\n", res);
        qsort(sets, N, sizeof(struct set), cmp);
        for (int i = 0; i < N; i++) {
            printf("%d->%d\n", sets[i].pre, sets[i].to);
        }
    }
    free(sets);
    free(graph);
    return 0;
}