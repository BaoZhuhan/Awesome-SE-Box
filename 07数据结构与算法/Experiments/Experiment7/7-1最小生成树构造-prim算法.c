#include <stdio.h>
#include <stdlib.h>

const int INF = __INT_MAX__;

struct GNode {
    int Nv;
    int Ne;
    int **G;
};

struct GNode *graph;
int *dist, *choiced, *parent;

int min(int a, int b) {
    return a > b ? b : a;
}

void buildG() {
    graph = (struct GNode *)malloc(sizeof(struct GNode));
    scanf("%d%d", &graph->Nv, &graph->Ne);
    dist = (int *)malloc((graph->Nv + 1) * sizeof(int));
    choiced = (int *)malloc((graph->Nv + 1) * sizeof(int));
    parent = (int *)malloc((graph->Nv + 1) * sizeof(int));
    graph->G = (int **)malloc((graph->Nv + 1) * sizeof(int *));
    for (int i = 1; i <= graph->Nv; i++) {
        graph->G[i] = (int *)malloc((graph->Nv + 1) * sizeof(int));
        for (int j = 1; j <= graph->Nv; j++) {
            graph->G[i][j] = INF;
        }
        dist[i] = INF;
        choiced[i] = 0;
        parent[i] = -1;
    }
    for (int i = 1; i <= graph->Ne; i++) {
        int pre, to, weight;
        scanf("%d%d%d", &pre, &to, &weight);
        graph->G[pre][to] = weight;
        graph->G[to][pre] = weight;
    }
}

void prim() {
    dist[1] = 0;
    choiced[1] = 1;
    parent[1] = -1;
    for (int i = 2; i <= graph->Nv; i++) {
        dist[i] = graph->G[1][i];
        parent[i] = 1;
    }
    for (int cnt = 1; cnt < graph->Nv; cnt++) {
        int temp = INF;
        int index = -1;
        for (int j = 1; j <= graph->Nv; j++) {
            if (!choiced[j] && dist[j] < temp) {
                temp = dist[j];
                index = j;
            }
        }
        if (index == -1)
            break;
        choiced[index] = 1;
        if (parent[index] < index)
            printf("%d,%d,%d\n", parent[index], index, dist[index]);
        else
            printf("%d,%d,%d\n", index, parent[index], dist[index]);
        for (int j = 1; j <= graph->Nv; j++) {
            if (!choiced[j] && graph->G[index][j] < dist[j]) {
                dist[j] = graph->G[index][j];
                parent[j] = index;
            }
        }
    }
}

int main() {
    buildG();
    prim();
    free(parent);
    free(choiced);
    free(dist);
    for (int i = 1; i <= graph->Nv; i++) {
        free(graph->G[i]);
    }
    free(graph->G);
    free(graph);
    return 0;
}