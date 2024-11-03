#include <stdio.h>
#include <stdlib.h>
#define INFINITY 1000000
#define MaxVertexNum 10
typedef int Vertex;
typedef int WeightType;
typedef struct GNode {
    int Nv;
    int Ne;
    WeightType G[MaxVertexNum][MaxVertexNum];
} *MGraph;

void ShortestDist(MGraph Graph, int dist[], Vertex S);

int main() {
    int dist[MaxVertexNum];
    int maxDist[MaxVertexNum];
    Vertex S, V;
    MGraph Ga = (MGraph)malloc(sizeof(struct GNode));
    int fx;
    int a, b, c;
    scanf("%d %d %d", &Ga->Nv, &Ga->Ne, &fx);
    for (int i = 0; i < Ga->Nv; i++) {
        for (int j = 0; j < Ga->Nv; j++) {
            if (i == j) {
                Ga->G[i][j] = 0;
            } else {
                Ga->G[i][j] = INFINITY;
            }
        }
    }
    for (int i = 0; i < Ga->Ne; i++) {
        scanf("%d %d %d", &a, &b, &c);
        if (fx == 0) {
            Ga->G[a - 1][b - 1] = c;
            Ga->G[b - 1][a - 1] = c;
        } else if (fx == 1) {
            Ga->G[a - 1][b - 1] = c;
        }
    }

    int mindex = 0;
    for (int i = 0; i < Ga->Nv; i++) {
        int max_distance = 0;
        for (int k = 0; k < Ga->Nv; k++) {
            ShortestDist(Ga, dist, k);
            if (dist[i] != INFINITY) {
                max_distance = (max_distance > dist[i]) ? max_distance : dist[i];
            }
            if (dist[i] == INFINITY) {
                max_distance = INFINITY;
            }
        }
        maxDist[i] = max_distance;
        if (i == 0 || maxDist[i] < maxDist[mindex]) {
            mindex = i;
        }
    }
    printf("%d", mindex + 1);

    free(Ga);
    return 0;
}

void ShortestDist(MGraph Graph, int dist[], Vertex S) {
    int visit[MaxVertexNum];
    for (int i = 0; i < Graph->Nv; i++) {
        dist[i] = Graph->G[S][i];
        visit[i] = 0;
    }
    dist[S] = 0;
    while (1) {
        int index = -1;
        int min = INFINITY;
        for (int i = 0; i < Graph->Nv; i++) {
            if (!visit[i] && dist[i] < min) {
                min = dist[i];
                index = i;
            }
        }
        if (index == -1) {
            break;
        }
        visit[index] = 1;
        for (int i = 0; i < Graph->Nv; i++) {
            if (Graph->G[index][i] != INFINITY && i != index) {
                if (Graph->G[index][i] + dist[index] < dist[i]) {
                    dist[i] = Graph->G[index][i] + dist[index];
                }
            }
        }
    }
    for (int i = 0; i < Graph->Nv; i++) {
        if (dist[i] == INFINITY) {
            dist[i] = -1;
        }
    }
}