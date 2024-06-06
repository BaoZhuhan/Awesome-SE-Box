#include <stdio.h>
#include <stdlib.h>
#define MVNum 10

int visited[MVNum];
typedef struct{
    char vexs[MVNum];
    int arcs[MVNum][MVNum];
    int vexnum, arcnum;
}Graph;

void CreateUDN(Graph& G);//实现细节隐藏
void BFS(Graph G, int v);
void BFSTraverse(Graph G){
    int v;
    for(v = 0; v < G.vexnum; ++v)  visited[v] = 0;
    for(v = 0; v < G.vexnum; ++v)
        if(!visited[v])  BFS(G, v);
}
int main(){
    Graph G;
    CreateUDN(G);
    BFSTraverse(G);
    return 0;
}

//below is my answer;

typedef struct queue{
    int* data;
    int start, end;
    int size;
}queue;

void push(queue* Q, int data){
    Q->end = (Q->end + 1) % Q->size;
    Q->data[Q->end % Q->size] = data;
}

void pop(queue* Q){
    Q->start = (Q->start + 1) % Q->size;
}

int front(queue* Q){
    return Q->data[(Q->start + 1) % Q->size];
}
void BFS(Graph G, int V){
    queue* Q;
    Q = (queue*)malloc(sizeof(queue));
    Q->size = MVNum+1;
    Q->data = (int*)malloc(Q->size * (sizeof(int)));
    Q->start = Q->end = 0;

    push(Q, V);
    visited[V] = 1;
    while(Q->start != Q->end){
        int now = front(Q);
        pop(Q);
        printf("%c ", G.vexs[now]);
        for(int i = 0; i < G.arcnum; i++){
            if(G.arcs[now][i] == 1 and visited[i] == 0){
                push(Q, i);
                visited[i] = 1;
            }
        }
    }
}