#include <stdio.h>
#include <stdlib.h>

#define MVNum 10

int visited[MVNum];
typedef struct ArcNode{
    int adjvex;
    struct ArcNode* nextarc;
    int info;
}ArcNode; //Edge

typedef struct VNode{
    char data;
    ArcNode* firstarc;
}VNode, AdjList[MVNum]; //Node

typedef struct{
    AdjList vertices;
    int vexnum, arcnum;
}ALGraph;


int CreateUDG(ALGraph& G){
    scanf("%d%d", &G.vexnum, &G.arcnum);

    for(int i = 0; i < G.vexnum; ++i){
        scanf(" %c", &G.vertices[i].data);
        G.vertices[i].firstarc = NULL;
    }

    for(int i = 0; i < G.arcnum; ++i){
        int v1, v2, info;
        scanf("%d%d%d", &v1, &v2, &info);//start node , end node ,info
        ArcNode* arc = (ArcNode*)malloc(sizeof(ArcNode));
        arc->adjvex = v2;
        arc->info = info;
        arc->nextarc = G.vertices[v1].firstarc;
        G.vertices[v1].firstarc = arc;
    }
    return 0;
}

int main(){
    ALGraph G;
    CreateUDG(G);
}