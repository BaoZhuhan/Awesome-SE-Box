#include <math.h>
int Fill(int stations[], int n, int k) {
    int sum = 0;
    for (int i = 0; i < k + 1; i++) {
        if (stations[i] > n) {
            return 0;
        }
        sum += stations[i];
    }
    return ceil(sum / n);
}