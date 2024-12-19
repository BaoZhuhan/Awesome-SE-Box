#include <stdio.h>
#include <stdlib.h>

struct node {
    int begin;
    int end;
};

// 插入排序
void insertionSort(struct node arr[], int n) {
    for (int i = 1; i < n; i++) {
        struct node key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].end > key.end) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n;
    // 读取活动数量
    scanf("%d", &n);
    struct node *a = (struct node *)malloc(n * sizeof(struct node));
    // 读取每个活动的开始和结束时间
    for (int i = 0; i < n; i++) scanf("%d %d", &a[i].begin, &a[i].end);
    // 对活动按结束时间进行排序
    insertionSort(a, n);
    int ans = 0;
    int time = a[0].begin;
    // 选择活动
    for (int i = 0; i < n; i++) {
        if (a[i].begin >= time) {
            ans++;
            time = a[i].end;
        }
    }
    // 输出最多可以进行的活动数量
    printf("%d", ans);
    return 0;
}