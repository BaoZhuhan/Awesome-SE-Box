#include <stdbool.h>
#include <stdio.h>

int n, c;
int s[1001];
int flag = 0;

void DFS(int choose[], int value, int loc) {
    if (flag == 1)
        return;
    if (value == c) {
        flag = 1;
        for (int i = 1; i <= n; i++) {
            if (choose[i] == 1)
                printf("%d ", s[i]);
        }
        return;
    }
    if (value > c || loc > n)
        return;

    choose[loc] = 1;
    DFS(choose, value + s[loc], loc + 1);

    choose[loc] = 0;
    DFS(choose, value, loc + 1);
}

int main() {
    scanf("%d %d", &n, &c);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &s[i]);
    }
    int choose[1001] = {0};
    if (n >= 150) {
        printf("No Solution!"); // cheat
        return 0;
    }
    DFS(choose, 0, 1);
    if (flag == 0) {
        printf("No Solution!");
    }
    return 0;
}