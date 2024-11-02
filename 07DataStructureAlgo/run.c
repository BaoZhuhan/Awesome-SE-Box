#include "code.c"

int main()
{
    int dist[MaxVertexNum];
    Vertex S, V;
    MGraph G = ReadG();

    scanf("%d", &S);
    ShortestDist( G, dist, S );

    for ( V=0; V<G->Nv; V++ )
        printf("%d ", dist[V]);

    return 0;
}
