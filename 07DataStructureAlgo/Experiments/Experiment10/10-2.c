#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char id[14];
    int score;
    int location_number;
    int local_rank;
    int final_rank;
};

int cmp(const void *a, const void *b) {
    struct Student *stuA = (struct Student *)a;
    struct Student *stuB = (struct Student *)b;
    if (stuA->score != stuB->score)
        return stuB->score - stuA->score;
    else
        return strcmp(stuA->id, stuB->id);
}

int main() {
    int N;
    scanf("%d", &N);
    struct Student total[30000];
    int total_count = 0;
    for (int i = 1; i <= N; ++i) {
        int K;
        scanf("%d", &K);
        struct Student local[300];
        for (int j = 0; j < K; ++j) {
            scanf("%s %d", local[j].id, &local[j].score);
            local[j].location_number = i;
        }
        qsort(local, K, sizeof(struct Student), cmp);
        local[0].local_rank = 1;
        for (int j = 1; j < K; ++j) {
            if (local[j].score == local[j - 1].score)
                local[j].local_rank = local[j - 1].local_rank;
            else
                local[j].local_rank = j + 1;
        }
        memcpy(total + total_count, local, K * sizeof(struct Student));
        total_count += K;
    }
    qsort(total, total_count, sizeof(struct Student), cmp);
    total[0].final_rank = 1;
    for (int i = 1; i < total_count; ++i) {
        if (total[i].score == total[i - 1].score)
            total[i].final_rank = total[i - 1].final_rank;
        else
            total[i].final_rank = i + 1;
    }
    printf("%d\n", total_count);
    for (int i = 0; i < total_count; ++i) {
        printf("%s %d %d %d\n", total[i].id, total[i].final_rank, total[i].location_number, total[i].local_rank);
    }
    return 0;
}
