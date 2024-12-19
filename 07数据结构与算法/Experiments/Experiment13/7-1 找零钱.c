#include <stdio.h>

int n, m;
int a[1001];
int ans = 0;

void DFS(int choose[], int value, int loc) {
    if (value == m) {
        ans++;
        int res[1001], res_size = 0;
        for (int i = 1; i <= loc; i++) {
            if (choose[i] == 1) {
                res[res_size++] = a[i];
            }
        }
        for(int i = 0 ; i < res_size - 1 ; i++) {
            printf("%d ", res[i]);
        }
        printf("%d\n", res[res_size - 1]);
        return;
    }

    if (value > m || loc > n)
        return;
    
    choose[loc] = 1;
    DFS(choose, value + a[loc], loc + 1);

    choose[loc] = 0;
    DFS(choose, value, loc + 1);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    scanf("%d", &m);
    int choose[1001] = {0};
    DFS(choose, 0, 1);
    if (ans == 0) {
        printf("None");
    }
    return 0;
}
