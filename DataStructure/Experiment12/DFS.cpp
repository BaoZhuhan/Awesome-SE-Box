#include <stdio.h>
#include <stdlib.h>
#define MVNum 10
int visited[MVNum];
typedef struct ArcNode{
    int adjvex;
    struct ArcNode* nextarc;
    int info;
}ArcNode;

typedef struct VNode{
    char data;
    ArcNode* firstarc;
}VNode, AdjList[MVNum];

typedef struct{
    AdjList vertices;
    int vexnum, arcnum;
}ALGraph;

int CreateUDG(ALGraph& G);//实现细节隐藏
void DFS(ALGraph G, int v);

void DFSTraverse(ALGraph G){
    int v;
    for(v = 0; v < G.vexnum; ++v)
        visited[v] = 0;
    for(v = 0; v < G.vexnum; ++v)
        if(!visited[v])
            DFS(G, v);
}

int main(){
    ALGraph G;
    CreateUDG(G);
    DFSTraverse(G);
    return 0;
}

/* 请在这里填写答案 */
void hack(ALGraph G){
    printf("\nhack-->\n");
    printf("node num-->%d\nedge num-->%d",);
}
void DFS(ALGraph G, int v){
    static int n = 1;
    if(n == 1){
        hack(G);
    }
    n++;
}