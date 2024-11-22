#include <stdio.h>
#include <stdlib.h>

int **graph;
int N;

void BuildGraph() {
    graph = (int **)calloc(N + 1, sizeof(int *));
    for (int i = 1; i <= N; i++) {
        graph[i] = (int *)calloc(N + 1, sizeof(int));
    }

    int task_N = 0;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &task_N);
        int target = 0;
        for (int j = 0; j < task_N; j++) {
            scanf("%d", &target);
            graph[target][i] = 1;
        }
    }
    return;
}

int inDegree(int index) {
    int res = 0;
    for (int i = 1; i <= N; i++) {
        if (graph[i][index] == 1)
            res++;
    }
    return res;
}

void cleanNode(int index) {
    for (int i = 1; i <= N; i++) {
        graph[index][i] = 0;
    }
}

int topo_sort() {
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
        cleanNode(index);
    }
    free(visited);
    return cot;
}

int main() {
    scanf("%d", &N);
    BuildGraph();
    int cot = topo_sort();
    printf("%d", (cot == N ? 1 : 0));
    return 0;
}