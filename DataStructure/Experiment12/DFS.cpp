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
typedef struct node_stack{
    int data;
    struct node_stack* next;
}stack;

stack* InitStack(){
    stack* S;
    S = (stack*)malloc(sizeof(stack));
    S->data = -1;
    S->next = nullptr;
    return S;
}

stack* Push(stack* old, int data){
    stack* S;
    S = (stack*)malloc(sizeof(stack));
    S->data = data;
    S->next = old;
    return S;
}

stack* Pop(stack* S){
    S = S->next;
    return S;
}

void DFS(ALGraph G, int v){
    stack* S = InitStack();
    S = Push(S, v);
    visited[v] = 1;
    while(S->next != nullptr){
        int now = S->data;
        S = Pop(S);
        printf("%c ", G.vertices[now].data);
        for(ArcNode* p = G.vertices[now].firstarc; p; p = p->nextarc){
            int w = p->adjvex;
            if(!visited[w]){
                S = Push(S, w);
                visited[w] = 1;
            }
        }
    }
}

void DFS(ALGraph G, int v){
    ArcNode* p;
    visited[v] = 1;
    printf("%c ", G.vertices[v].data);
    for(p = G.vertices[v].firstarc; p; p = p->nextarc){
        if(!visited[p->adjvex]) DFS(G, p->adjvex);
    }
}
