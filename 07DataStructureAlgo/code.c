#include "test.c"

int calInDegree(LGraph graph, int v) {
    int innerDegree = 0;

    int *visited = (int *)calloc(graph->n_verts * sizeof(int));

    for (int i = 0; i < graph->n_verts; i++) {
        Position cnt = graph->ver_list[i]->adj;
        while (cnt != NULL) {
            if (cnt->dest == v && visited[cnt->dest] == 0) {
                innerDegree++;
                printf("find innerDegree : i->%d\n", i);
                visited[cnt->dest] = 1;
            }
            cnt = cnt->next;
        }
    }
    printf("calindegree-> %d, retrun %d\n", v, innerDegree);
    free(visited);
    return innerDegree;
}

bool IsAcyclic(LGraph graph) {
    int visitCot = 0;
    int *visited = (int *)calloc(graph->n_verts * sizeof(int));
    // Warning !
    int dbcot = 0;
    while (visitCot < graph->n_verts) {
        dbcot++;
        printf("while -->%d\n", dbcot);
        int index = -1;
        for (int i = 0; i < graph->n_verts; i++) {
            if (visited[i] == 0 && calInDegree(graph, i) == 0) {
                index = i;
                break;
            }
        }
        printf("index-->%d\n", index);
        if (index == -1)
            break;

        visitCot++;
        visited[index] = 1;
        graph->ver_list[index]->adj = NULL;
    }

    printf("Debug : visitCot = %d, graph->n = %d\n", visitCot, graph->n_verts);
    for (int i = 0; i < graph->n_verts; i++) {
        printf("%d ", visited[i]);
    }
    printf("\n");

    free(visited);
    return visitCot != graph->n_verts;
}