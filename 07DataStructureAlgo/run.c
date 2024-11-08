#include "code.c"

int main() {
    int i, j, N;
    Vertex Seq[MaxVertexNum];
    LGraph G = ReadG();
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        for (j = 0; j < G->Nv; j++)
            scanf("%d", &Seq[j]);
        if (IsTopSeq(G, Seq))
            printf("yes\n");
        else
            printf("no\n");
    }

    return 0;
}