#include "test.c"

struct Queue {
    int *Q;
    int head;
    int end; // end is ^
    int capacity;
};

int calInDegree(LGraph graph, int v) {
    for (int i = 0; i < graph->m_edges; i++) {
        Position cnt;
    }
}

int calDegree(LGraph graph, int v) {
    if (graph->directed == true)
        return calInDegree(graph, v);
}

bool IsAcyclic(LGraph graph) {
}