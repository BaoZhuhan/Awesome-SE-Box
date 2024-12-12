#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

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

// LGraph ReadG() {
//     LGraph Graph = (LGraph)malloc(sizeof(struct GNode));
//     scanf("%d%d", &Graph->Nv, &Graph->Ne);
//     for (int i = 0; i < Graph->Ne; i++) {
//         int a, b;
//         scanf("%d%d", &a, &b);
//         struct AdjVNode *newNode = (struct AdjVNode *)malloc(sizeof(struct AdjVNode));
//         newNode->AdjV = b;
//         newNode->Next = NULL;
//         struct AdjVNode *ptr = Graph->G[a].FirstEdge;
//         if (ptr == NULL) {
//             Graph->G[a].FirstEdge = newNode;
//             continue;
//         }
//         while (ptr->Next != NULL) {
//             ptr = ptr->Next;
//         }
//         ptr->Next = newNode;
//     }
//     return Graph;
// }

LGraph ReadG() {
    int i;
    LGraph LG = (LGraph)malloc(sizeof(struct GNode));
    for (int j = 0; j < 10; j++)
        LG->G[j].FirstEdge = NULL;
    scanf("%d %d", &LG->Nv, &LG->Ne);
    for (i = 0; i < LG->Ne; ++i) {
        int p1, p2;
        PtrToAdjVNode adj = (struct AdjVNode *)malloc(sizeof(struct AdjVNode));
        scanf("%d %d", &p1, &p2);
        p1--;
        p2--; // 注意这里，他输入后都减了1！！！
        adj->AdjV = p2;
        adj->Next = NULL;
        if (LG->G[p1].FirstEdge == NULL) {
            LG->G[p1].FirstEdge = adj;
        } else {
            adj->Next = LG->G[p1].FirstEdge;
            LG->G[p1].FirstEdge = adj;
        }
    }
    return LG;
}
