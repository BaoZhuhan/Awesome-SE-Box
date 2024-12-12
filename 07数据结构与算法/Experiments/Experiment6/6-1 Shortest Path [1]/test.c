#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MaxVertexNum 10 /* maximum number of vertices */
typedef int Vertex;     /* vertices are numbered from 0 to MaxVertexNum-1 */

typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode {
    Vertex AdjV;
    PtrToAdjVNode Next;
};

typedef struct Vnode {
    PtrToAdjVNode FirstEdge;
} AdjList[MaxVertexNum];

typedef struct GNode *PtrToGNode;
struct GNode {
    int Nv;
    int Ne;
    AdjList G;
};
typedef PtrToGNode LGraph;

LGraph ReadG() {
    LGraph Graph = (LGraph)malloc(sizeof(struct GNode));
    scanf("%d%d", &Graph->Nv, &Graph->Ne);
    for (int i = 0; i < Graph->Nv; i++) {
        Graph->G[i].FirstEdge = NULL;
    }
    for (int i = 0; i < Graph->Ne; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        PtrToAdjVNode newNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
        newNode->AdjV = b;
        newNode->Next = Graph->G[a].FirstEdge;
        Graph->G[a].FirstEdge = newNode;
    }
    return Graph;
}

void Debug(LGraph Graph, int dist[], int path[], int collected[]) {
    printf("-----Debug------\n");
    printf("node dist path collected\n");
    for (int i = 0; i < Graph->Nv; i++) {
        printf("%4d %4d %4d %d\n", i, dist[i], path[i], collected[i]);
    }
    printf("----------------\n");
    return;
}