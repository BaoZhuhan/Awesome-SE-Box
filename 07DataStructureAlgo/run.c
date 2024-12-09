#include <stdio.h>
#include <stdlib.h>

int orderLen(int *list, int base, int capacity) {
    if (base >= capacity)
        return 0;
    int len = 1;
    for (int i = base + 1; i < capacity; i++) {
        if (list[i] >= list[i - 1])
            len++;
        else
            break;
    }
    return len;
}

int judge(int *unsort, int *sorted, int capacity) {
    
}

int main() {
    int n = 0;
    scanf("%d", &n);
    int *unsort = (int *)malloc(n * sizeof(int));
    int *sorted = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", unsort + i);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", sorted + i);
    }
    int flag = judge(unsort, sorted);

    return 0;
}