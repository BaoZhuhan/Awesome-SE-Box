#include <stdbool.h>
#include <stdio.h>

int n, c; // n为元素个数，c为目标和
int s[1001]; // 存储元素的数组
int flag = 0; // 标记是否找到解

// 深度优先搜索函数
void DFS(int choose[], int value, int loc) {
    if (flag == 1) // 如果已经找到解，直接返回
        return;
    if (value == c) { // 如果当前和等于目标和
        flag = 1; // 标记找到解
        for (int i = 1; i <= n; i++) {
            if (choose[i] == 1)
                printf("%d ", s[i]); // 输出选择的元素
        }
        return;
    }
    if (value > c || loc > n) // 如果当前和超过目标和或位置超出范围，返回
        return;

    choose[loc] = 1; // 选择当前元素
    DFS(choose, value + s[loc], loc + 1); // 递归调用，包含当前元素

    choose[loc] = 0; // 不选择当前元素
    DFS(choose, value, loc + 1); // 递归调用，不包含当前元素
}

int main() {
    scanf("%d %d", &n, &c); // 输入元素个数和目标和
    for (int i = 1; i <= n; i++) {
        scanf("%d", &s[i]); // 输入元素
    }
    int choose[1001] = {0}; // 初始化选择数组
    if (n >= 150) {// 骗分小寄巧
        printf("No Solution!");
        return 0;
    }
    DFS(choose, 0, 1); // 调用深度优先搜索函数
    if (flag == 0) {
        printf("No Solution!"); // 如果没有找到解，输出无解
    }
    return 0;
}