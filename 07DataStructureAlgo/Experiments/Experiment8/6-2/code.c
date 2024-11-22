#include "test.c"

bool IsAcyclic(LGraph graph) {
    int cot = 0;
    int *inDegree = (int *)calloc(graph->n_verts, sizeof(int));

    for (int i = 0; i < graph->n_verts; i++) {
        Position cnt = graph->ver_list[i]->adj;
        while (cnt != NULL) {
            inDegree[cnt->dest]++;
            cnt = cnt->next;
        }
    }

    for (int i = 0; i < graph->n_verts; i++)
        cot += inDegree[i] == 0 ? 1 : 0;

    int visited = 0;
    while (cot > 0) {
        for (int i = 0; i < graph->n_verts; i++) {
            if (inDegree[i] == 0) {
                inDegree[i] = -1;
                visited++;
                cot--;
                Position cnt = graph->ver_list[i]->adj;
                while (cnt != NULL) {
                    if (inDegree[cnt->dest] > 0)
                        inDegree[cnt->dest]--;
                    cnt = cnt->next;
                }
            }
        }
    }

    free(inDegree);
    return visited == graph->n_verts;
}