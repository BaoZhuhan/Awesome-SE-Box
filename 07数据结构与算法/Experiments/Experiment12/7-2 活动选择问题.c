#include <stdio.h>
#include <stdlib.h>

struct node {
    int begin;
    int end;
};

int main() {
    int n;
    scanf("%d", &n);
    struct node *a = (struct node *)malloc(n * sizeof(struct node));
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a[i].begin, &a[i].end);
    }
    for (int i = 0; i < n - 1; i++) {
        int index = i;
        for (int j = i; j < n; j++) {
            if (a[j].end < a[index].end) {
                index = j;
            }
        }
        struct node temp = a[index];
        a[index] = a[i];
        a[i] = temp;
    }
    int ans = 0;
    int time = a[0].begin;
    for (int i = 0; i < n; i++) {
        // printf("%d %d %d\n",a[i].begin , a[i].end , time );
        if (a[i].begin >= time) {
            ans++;
            time = a[i].end;
        }
    }
    printf("%d", ans);
    return 0;
}