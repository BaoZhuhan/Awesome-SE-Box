#include <stdio.h>
#include <stdlib.h>

struct node {
    int v;
    int visit;
    int weight;
    int parent;
};

const int INF = 10000;
int N, M;
int w[25][25];
struct node *village;

int min(int a, int b) {
    return a > b ? b : a;
}
int max(int a, int b) {
    return a > b ? a : b;
}

void debug() {
    // debug
    printf("-start-\n");
    printf("V     : ");
    for (int i = 0; i <= N; i++) {
        printf("%6d ", i);
    }
    printf("\nvisit : ");
    for (int i = 0; i <= N; i++) {
        printf("%6d ", village[i].visit);
    }
    printf("\nweight: ");
    for (int i = 0; i <= N; i++) {
        printf("%6d ", village[i].weight);
    }
    printf("\nparent: ");
    for (int i = 0; i <= N; i++) {
        printf("%6d ", village[i].parent);
    }
    printf("\n--end--\n");
    // debug
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d%d", &N, &M);

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            w[i][j] = INF;
            if (i == j)
                w[i][j] = 0;
        }
    }

    for (int i = 1; i <= M; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        w[a][b] = c;
        w[b][a] = c;
    }

    village = (struct node *)malloc((N + 1) * sizeof(struct node));

    for (int i = 1; i <= N; i++) {
        village[i].v = i;
        village[i].visit = 0;
        village[i].weight = w[1][i];
        village[i].parent = 1;
    }

    village[1].visit = 1;
    village[0].weight = INF; // Sentry

    int count = 1;
    while (count < N) {
        // debug();
        int index = 0;
        for (int i = 1; i <= N; i++) {
            if (village[i].visit == 0 && village[i].weight < village[index].weight) {
                index = i;
            }
        }
        village[index].visit = 1;
        printf("%d,%d,%d\n", min(village[index].v, village[index].parent), max(village[index].v, village[index].parent),
               village[index].weight);
        for (int i = 1; i <= N; i++) {
            if (w[index][i] < village[i].weight && village[i].visit == 0) {
                village[i].weight = w[index][i];
                village[i].parent = index;
            }
        }
        count++;
    }
    // debug();

    free(village);
    return 0;
}
