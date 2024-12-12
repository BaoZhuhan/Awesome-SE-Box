#include <bits/stdc++.h>
using namespace std;

int op[100];
int z[100];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    int n, m, x, y;
    cin >> n >> m >> x >> y;

    char a[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            a[i][j] = getchar();
        }

        getchar();
    }

    int p, q;
    cin >> p >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> op[i] >> z[i];
    }

    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < q; j++)
        {

            if (op[j] == 1)
            {
                char tmp = a[z[j] - 1][m - 1];
                for (int k = m - 1; k > 0; k--)
                {
                    a[z[j] - 1][k] = a[z[j] - 1][k - 1];
                }
                a[z[j] - 1][0] = tmp;
            }

            if (op[j] == 2)
            {
                char tmp = a[n - 1][z[j] - 1];
                for (int k = n - 1; k > 0; k--)
                {
                    a[k][z[j] - 1] = a[k - 1][z[j] - 1];
                }
                a[0][z[j] - 1] = tmp;
            }

        }
    }

    cout << a[x - 1][y - 1];

    return 0;
}