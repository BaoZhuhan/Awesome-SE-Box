#include "test.h"

#define MaxVertexNum 10 /* maximum number of vertices */
typedef int Vertex;     /* vertices are numbered from 1 to MaxVertexNum */

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
    for (int i = 0; i < Graph->Ne; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        struct AdjVNode *newNode = (struct AdjVNode *)malloc(sizeof(struct AdjVNode));
        newNode->AdjV = b;
        newNode->Next = NULL;
        struct AdjVNode *ptr = Graph->G[a].FirstEdge;
        if (ptr == NULL) {
            Graph->G[a].FirstEdge = newNode;
            continue;
        }
        while (ptr->Next != NULL) {
            ptr = ptr->Next;
        }
        ptr->Next = newNode;
    }
    return Graph;
}