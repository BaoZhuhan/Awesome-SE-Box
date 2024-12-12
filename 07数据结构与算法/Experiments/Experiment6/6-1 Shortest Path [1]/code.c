#include "test.c"

void initDijkstra(LGraph Graph, int S, int collected[], int path[], int dist[]) {
    for (int i = 0; i < Graph->Nv; i++) {
        collected[i] = 0;
        path[i] = -1;
        dist[i] = __INT_MAX__;
    }
    path[S] = S;
    dist[S] = 0;
}

int findMin(LGraph Graph, int collected[], int path[], int dist[]) {
    int loc = -1;
    int minDist = __INT_MAX__;
    for (int i = 0; i < Graph->Nv; i++) {
        if (collected[i] == 0 && dist[i] < minDist) {
            loc = i;
            minDist = dist[i];
        }
    }
    return loc;
}

void ShortestDist(LGraph Graph, int dist[], Vertex S) {
    int collected[MaxVertexNum];
    int path[MaxVertexNum];
    initDijkstra(Graph, S, collected, path, dist);
    int loc = findMin(Graph, collected, path, dist);
    while (loc != -1) {
        struct AdjVNode *V = Graph->G[loc].FirstEdge;
        while (V != NULL) {
            if (dist[loc] + 1 < dist[V->AdjV]) {
                dist[V->AdjV] = dist[loc] + 1;
                path[V->AdjV] = loc;
            }
            V = V->Next;
        }
        collected[loc] = 1;
        loc = findMin(Graph, collected, path, dist);
    }

    for (int i = 0; i < Graph->Nv; i++) {
        if (path[i] == -1)
            dist[i] = -1;
    }
}