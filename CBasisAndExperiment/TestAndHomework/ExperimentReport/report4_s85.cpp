#include <stdio.h>
int main()
{
    int m, n, c, d, sum, bs;
    sum = 0;
    bs = 0;
    scanf("%d%d", &m, &n);
    getchar();
    char a[m][n];
    int e[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%c", &a[i][j]);
            if (a[i][j] == '#')
            {
                e[i][j] = 2;
            }
            if (a[i][j] == '0')
            {
                e[i][j] = -1;
            }
        }
        getchar();
    }
    int rz;
    scanf("%d", &rz);
    for (int i = 0; i < rz; i++)
    {
        int count;
        count = 0;
        scanf("%d%d", &c, &d);
        e[c][d] = e[c][d] - 2;
        if (c > 0)
        {
            e[c - 1][d] = e[c - 1][d] - 1;
        }
        if (c < m - 1)
        {
            e[c + 1][d] = e[c + 1][d] - 1;
        }
        if (d > 0)
        {
            e[c][d - 1] = e[c][d - 1] - 1;
        }
        if (d < n - 1)
        {
            e[c][d + 1] = e[c][d + 1] - 1;
        }
        for (int k = 0; k < m; k++)
        {
            for (int j = 0; j < n; j++)
            {
                if (e[k][j] == 0 )
                {
                    count++;
                    e[k][j] = -1;
                    a[k][j] = 'D';
                }
                if(e[k][j] == 1 ){
                    a[k][j] = 'H';
                }
            }
        }
        printf("%d\n", count);
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == 'H')
            {
                bs++;
            }
            if (a[i][j] == 'D'){
                sum++;
            }
        }
    }
    printf("%d %d", sum, bs);
    return 0;
}