#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

typedef int Vertex;                /* 顶点编号类型 */
typedef char VertInfo;             /* 顶点信息类型 */
typedef struct EdgeNode *Position; /* 指针即结点位置 */
struct EdgeNode {
    Vertex dest;   /* 边的另一端点编号 */
    Position next; /* 线性表中下一个元素的位置 */
};
typedef struct HeadNode *AdjList; /* 邻接表 */
struct HeadNode {
    Position adj;  /* 邻接表头指针 */
    VertInfo data; /* 存储顶点信息 */
};
typedef struct LGraphNode *LGraph; /* 邻接表表示的图 */
struct LGraphNode {
    int n_verts;       /* 顶点数 */
    int m_edges;       /* 边数 */
    AdjList *ver_list; /* 存储顶点邻接表 */
    bool directed;     /* true为有向图，false为无向图 */
};

#define kMaxV 1000
/* 裁判实现，细节略 */
void InitGraph(LGraph graph, int kMaxVertex, bool directed);
bool ExistEdge(LGraph graph, Vertex u, Vertex v);
void InsertEdge(LGraph graph, Vertex u, Vertex v);
LGraph BuildGraph();
/* 裁判实现部分结束 */
