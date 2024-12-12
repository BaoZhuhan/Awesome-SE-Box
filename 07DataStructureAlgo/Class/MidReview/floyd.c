#include <stdio.h>

#define MAXNUMV 15
#define INF 1000000

int graph[MAXNUMV][MAXNUMV];
int dist[MAXNUMV][MAXNUMV];
int numV, numE, flag;

void buildGraph() {
    scanf("%d%d%d", &numV, &numE, &flag);
    for (int i = 1; i <= numV; i++) {
        for (int j = 1; j <= numV; j++) {
            graph[i][j] = 0;
            dist[i][j] = INF;
            if (i == j) {
                graph[i][j] = 1;
                dist[i][j] = 0;
            }
        }
    }
    int a, b, weight;
    for (int i = 1; i <= numE; i++) {
        scanf("%d%d%d", &a, &b, &weight);
        graph[a][b] = 1;
        dist[a][b] = weight;
        if (flag == 0) {
            graph[b][a] = 1;
            dist[b][a] = weight;
        }
    }
}

void floyd() {
    for (int k = 1; k <= numV; k++) {
        for (int i = 1; i <= numV; i++) {
            for (int j = 1; j <= numV; j++) {
                if (graph[i][k] == 0 || graph[k][j] == 0)
                    continue;
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    graph[i][j] = 1;
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main() {
    buildGraph();
    floyd();

    int ans = -1;
    int minMaxDist = INF;
    for (int i = 1; i <= numV; i++) {
        int flagAble = 1;
        int maxDist = -1;
        for(int j = 1 ; j <= numV ; j++) {
            if(graph[j][i] == -1) {
                flagAble = 0;
                break;
            }
            if(dist[j][i] > maxDist) {
                maxDist = dist[j][i];
            }
        }
        if(flagAble == 1 && minMaxDist > maxDist){
            ans = i;
            minMaxDist = maxDist;
        }
    }
    printf("%d\n", ans);
    return 0;
}