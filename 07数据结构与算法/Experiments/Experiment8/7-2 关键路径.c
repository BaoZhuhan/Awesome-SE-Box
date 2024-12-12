#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 210

int n, e;
int adj[MAX_N][MAX_N];     // 邻接矩阵，存储边的权值
int inDegree[MAX_N];       // 记录每个顶点的入度
int ve[MAX_N];             // 事件的最早发生时间
int vl[MAX_N];             // 事件的最迟发生时间
int topoOrder[MAX_N];      // 拓扑序列
int edge_u[MAX_N * MAX_N]; // 边的起点
int edge_v[MAX_N * MAX_N]; // 边的终点
int edge_w[MAX_N * MAX_N]; // 边的权值
int edgeNum;

int queue[MAX_N];
int front, rear;

// 拓扑排序，返回1表示无环，返回0表示有环
int TopologicalSort() {
    front = rear = 0;
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0)
            queue[rear++] = i;
    }
    while (front != rear) {
        int u = queue[front++];
        topoOrder[count++] = u;
        for (int v = 1; v <= n; v++) {
            if (adj[u][v]) {
                inDegree[v]--;
                if (inDegree[v] == 0)
                    queue[rear++] = v;
                if (ve[u] + adj[u][v] > ve[v]) {
                    ve[v] = ve[u] + adj[u][v];
                }
            }
        }
    }
    if (count != n)
        return 0;
    return 1;
}

// 关键路径算法
void CriticalPath() {
    // 初始化vl
    int maxTime = ve[topoOrder[n - 1]];
    for (int i = 1; i <= n; i++) {
        vl[i] = maxTime;
    }
    // 计算vl
    for (int i = n - 1; i >= 0; i--) {
        int u = topoOrder[i];
        for (int v = 1; v <= n; v++) {
            if (adj[u][v]) {
                if (vl[v] - adj[u][v] < vl[u]) {
                    vl[u] = vl[v] - adj[u][v];
                }
            }
        }
    }
    // 找到所有关键活动
    int criticalEdges[MAX_N * MAX_N][2];
    int criticalEdgeNum = 0;
    for (int i = 0; i < edgeNum; i++) {
        int u = edge_u[i];
        int v = edge_v[i];
        int w = edge_w[i];
        int e = ve[u];
        int l = vl[v] - w;
        if (e == l) {
            criticalEdges[criticalEdgeNum][0] = u;
            criticalEdges[criticalEdgeNum][1] = v;
            criticalEdgeNum++;
        }
    }
    // 按照要求排序
    for (int i = 0; i < criticalEdgeNum - 1; i++) {
        for (int j = 0; j < criticalEdgeNum - i - 1; j++) {
            if (criticalEdges[j][0] > criticalEdges[j + 1][0] ||
                (criticalEdges[j][0] == criticalEdges[j + 1][0] && criticalEdges[j][1] > criticalEdges[j + 1][1])) {
                int temp0 = criticalEdges[j][0];
                int temp1 = criticalEdges[j][1];
                criticalEdges[j][0] = criticalEdges[j + 1][0];
                criticalEdges[j][1] = criticalEdges[j + 1][1];
                criticalEdges[j + 1][0] = temp0;
                criticalEdges[j + 1][1] = temp1;
            }
        }
    }
    // 输出结果
    printf("%d\n", maxTime);
    for (int i = 0; i < criticalEdgeNum; i++) {
        printf("%d->%d\n", criticalEdges[i][0], criticalEdges[i][1]);
    }
}

int main() {
    while (scanf("%d%d", &n, &e) != EOF) {
        memset(adj, 0, sizeof(adj));
        memset(inDegree, 0, sizeof(inDegree));
        memset(ve, 0, sizeof(ve));
        edgeNum = 0;
        int u, v, w;
        for (int i = 0; i < e; i++) {
            scanf("%d%d%d", &u, &v, &w);
            adj[u][v] = w;
            inDegree[v]++;
            edge_u[edgeNum] = u;
            edge_v[edgeNum] = v;
            edge_w[edgeNum] = w;
            edgeNum++;
        }
        if (!TopologicalSort()) {
            printf("unworkable project\n");
        } else {
            CriticalPath();
        }
    }
    return 0;
}