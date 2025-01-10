#include <stdio.h>
#include <stdlib.h>

int n, *matrix, **dp;

int DP() {
    for (int r = 2; r <= n; r++) {
        for (int i = 1; i <= n - r + 1; i++) {
            int j = i + r - 1;
            dp[i][j] = dp[i + 1][j] + matrix[i - 1] * matrix[i] * matrix[j];
            for (int k = i + 1; k < j; k++) {
                int t = dp[i][k] + dp[k + 1][j] + matrix[i - 1] * matrix[k] * matrix[j];
                if (t < dp[i][j])
                    dp[i][j] = t;
            }
        }
    }
    return dp[1][n];
}

int main() {
    scanf("%d", &n);

    matrix = calloc(n + 1, sizeof(int));
    for (int i = 0; i < n + 1; i++)
        scanf("%d", matrix + i);
    dp = calloc(n + 1, sizeof(int *));
    for (int i = 0; i <= n; i++)
        dp[i] = calloc(n + 1, sizeof(int));

    printf("%d\n", DP());

    for (int i = 0; i <= n; i++)
        free(dp[i]);
    free(dp);
    free(matrix);
    return 0;
}