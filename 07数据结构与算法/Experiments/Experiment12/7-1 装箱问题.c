#include <stdio.h>
#include <stdlib.h>

struct node {
    int weight;
    int loc;
};

int main() {
    int n;
    scanf("%d", &n);
    int *b = (int *)malloc(sizeof(int) * n);
    struct node *a = (struct node *)malloc(sizeof(struct node) * n);
    for (int i = 0; i < n; i++) {
        b[i] = 0;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].weight);
        for (int j = 0; j < n; j++) {
            if (b[j] + a[i].weight <= 100) {
                if (b[j] == 0)
                    ans++;
                b[j] = b[j] + a[i].weight;
                a[i].loc = j + 1;
                break;
            }
        }
        printf("%d %d\n", a[i].weight, a[i].loc);
    }
    printf("%d", ans);
    return 0;
}