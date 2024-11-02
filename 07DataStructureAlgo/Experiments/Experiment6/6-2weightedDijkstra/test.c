#include <stdio.h>
#include <stdlib.h>

#include <stdbool.h>
#define INFINITY 1000000
#define MaxVertexNum 10 /* maximum number of vertices */
typedef int Vertex;     /* vertices are numbered from 0 to MaxVertexNum-1 */
typedef int WeightType;

typedef struct GNode *PtrToGNode;
struct GNode {
    int Nv;
    int Ne;
    WeightType G[MaxVertexNum][MaxVertexNum];
};
typedef PtrToGNode MGraph;

MGraph ReadG() {
    MGraph Graph = (MGraph)malloc(sizeof(struct GNode));
    scanf("%d%d", &Graph->Nv, &Graph->Ne);
    for (int i = 0; i < Graph->Ne; i++) {
        for (int j = 0; j < Graph->Ne; j++) {
            Graph->G[i][j] = INFINITY;
            if (i == j)
                Graph->G[i][j] = 0;
        }
    }
    int a, b, weight;
    for (int i = 0; i < Graph->Ne; i++) {
        scanf("%d%d%d", &a, &b, &weight);
        Graph->G[a][b] = weight;
    }
    return Graph;
}

void Debug(MGraph Graph, int dist[], int path[], int collected[]) {
    printf("-----Debug------\n");
    printf("node dist path collected\n");
    for (int i = 0; i < Graph->Nv; i++) {
        printf("%4d %4d %4d %d\n", i, dist[i], path[i], collected[i]);
    }
    printf("----------------\n");
    return;
}