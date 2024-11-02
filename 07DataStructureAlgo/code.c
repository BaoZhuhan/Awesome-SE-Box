#include "test.c"

void initDijkstra(MGraph Graph, int S, int collected[], int path[], int dist[]) {
    for (int i = 0; i < Graph->Nv; i++) {
        collected[i] = 0;
        path[i] = -1;
        dist[i] = INFINITY;
    }
    path[S] = S;
    dist[S] = 0;
}

int findMin(MGraph Graph, int collected[], int path[], int dist[]) {
    int loc = -1;
    int minDist = INFINITY;
    for (int i = 0; i < Graph->Nv; i++) {
        if (collected[i] == 0 && dist[i] < minDist) {
            loc = i;
            minDist = dist[i];
        }
    }
    return loc;
}

void ShortestDist(MGraph Graph, int dist[], Vertex S) {
    int collected[MaxVertexNum];
    int path[MaxVertexNum];
    initDijkstra(Graph, S, collected, path, dist);
    int loc = findMin(Graph, collected, path, dist);
    while (loc != -1) {
        for(int cur = 0 ; cur < Graph->Ne ; cur++ ){
            if(Graph->G[loc][cur] == INFINITY) continue;
            if(dist[loc] + Graph->G[loc][cur] < dist[cur]){
                dist[cur] = dist[loc] + Graph->G[loc][cur];
                path[cur] = loc;
            }
        }
        collected[loc] = 1;
        loc = findMin(Graph, collected, path, dist);
    }

    for (int i = 0; i < Graph->Nv; i++) {
        if (path[i] == -1)
            dist[i] = -1;
    }
}