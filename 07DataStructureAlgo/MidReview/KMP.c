#include <stdio.h>
#include <stdlib.h>
int find(int one, int people[]);
int main(void) {
    int M, N;
    int max = 1;
    scanf("%d %d", &M, &N);
    int people[30001];
    int number[30001];
    for (int i = 0; i < M + 1; i++) {
        people[i] = i;
        number[i] = 1;
    }
    for (int i = 0; i < N; i++) {
        int a, count;
        int root;
        scanf("%d", &count);
        for (int j = 0; j < count; j++) {
            scanf("%d", &a);
            if (!j)
                root = find(a, people);
            else {
                a = find(a, people);

                if (a != root) {
                    people[a] = root;
                    number[root] = number[root] + number[a];
                    if (max <= number[root]) {
                        max = number[root];
                    }
                }
            }
        }
    }
    printf("%d", max);
    return 0;
}

int find(int one, int people[]) {
    int root;
    if (one == people[one]) {
        root = one;
    } else {
        int a = one;
        one = people[one];
        root = find(one, people);
        people[a] = root;
    }

    return root;
}

int find(int one, int people[]) {
    return people[one] == one ? one : find(people[one],people);
}