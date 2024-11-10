#include <stdio.h>
struct node {
    int v;
    int visit;
    int weight;
    int next;
};
int main() {
    freopen("input.txt", "r", stdin);
    int N, M;
    scanf("%d %d", &N, &M);
    int w[N + 1][N + 1];
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            w[i][j] = 10000;
        }
    }
    struct node village[N + 1];
    for (int i = 0; i < M; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        w[a][b] = c;
        w[b][a] = c;
    }
    for (int i = 1; i <= N; i++) {
        village[i].v = i;
        village[i].visit = 0;
        village[i].weight = w[1][i];
        village[i].next = 1;
    }
    village[1].visit = 1;
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
    printf("\nnext  : ");
    for (int i = 0; i <= N; i++) {
        printf("%6d ", village[i].next);
    }
    printf("\n--end--\n");
    // debug
    while (1) {
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
        printf("\nnext  : ");
        for (int i = 0; i <= N; i++) {
            printf("%6d ", village[i].next);
        }
        printf("\n--end--\n");
        // debug
        int min = 10000;
        int index = -1;
        for (int i = 1; i <= N; i++) {
            if (village[i].visit == 0 && village[i].weight < min) {
                min = village[i].weight;
                index = i;
            }
        }
        if (index == -1) {
            break;
        }
        village[index].visit = 1;
        for (int i = 1; i <= N; i++) {
            if (w[index][i] < village[i].weight && village[i].visit == 0) {
                village[i].weight = w[index][i];
                village[i].next = index;
            }
        }
    }
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
    printf("\nnext  : ");
    for (int i = 0; i <= N; i++) {
        printf("%6d ", village[i].next);
    }
    printf("\n--end--\n");
    // debug

    int count = 0;
    while (count < N - 1) {
        for (int i = 1; i <= N; i++) {
            for (int j = i + 1; j <= N; j++) {
                if (village[i].next == j) {
                    printf("%d,%d,%d\n", i, j, village[i].weight);
                    count++;
                }
                if (village[j].next == i) {
                    printf("%d,%d,%d\n", i, j, village[j].weight);
                    count++;
                }
            }
        }
    }
}