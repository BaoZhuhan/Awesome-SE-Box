#include <stdio.h>
#include <stdlib.h>

struct node {
    int index;
    int sorce;
    int goal;
    int all;
};

int n = 0;
int m = 0;

// A排前面返回1
int compare(struct node A, struct node B) {
    if (A.sorce > B.sorce) {
        return 1;
    } else if (B.sorce > A.sorce) {
        return 0;
    } else if (A.goal > B.goal) {
        return 1;
    } else if (A.goal < B.goal) {
        return 0;
    } else if (A.all > B.all) {
        return 1;
    } else if (A.all < B.all) {
        return 0;
    } else {
        return A.index < B.index ? 1 : 0;
    }
}

/* 冒泡排序 */
void bubble_sort(struct node teams[], int size) {
    for (int i = size - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (compare(teams[j], teams[j + 1]) == 0) {
                struct node temp = teams[j];
                teams[j] = teams[j + 1];
                teams[j + 1] = temp;
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    m = n * (n - 1) / 2;
    struct node teams[n];
    // 赋初值
    for (int i = 0; i < n; i++) {
        teams[i].all = 0;
        teams[i].goal = 0;
        teams[i].sorce = 0;
        teams[i].index = i;
    }

    for (int i = 0; i < m; i++) {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);

        teams[a - 1].all += c;
        teams[b - 1].all += d;

        if (c == d) {
            teams[a - 1].sorce += 1;
            teams[b - 1].sorce += 1;
        } else if (c > d) {
            teams[a - 1].sorce += 3;
        } else {
            teams[b - 1].sorce += 3;
        }

        teams[a - 1].goal += (c - d);
        teams[b - 1].goal += (d - c);
    }

    bubble_sort(teams, n); // 调用排序函数；

    for (int i = 0; i < n; i++) {
        printf("%d ", teams[i].index+1);
    }

    return 0;
}