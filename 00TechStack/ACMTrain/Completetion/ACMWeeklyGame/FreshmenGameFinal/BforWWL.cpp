#include <stdio.h>

void solve()
{
    int ans = 0;
    int x, y;
    scanf("%d,%d", &x, &y);
    int bits = sizeof(int); // 因为要由高位向低位取，所以要知道最高位。
    for (int i = bits - 1; i >= 0; i--)
    {
        int tmp ;
        tmp = x;
        for (int j = 0; j < i; j++)
        {
            tmp = tmp / 2;
        }
        tmp = (tmp & 1);
        int tmpx = tmp;
        tmp = y;
        for (int j = 0; j < i; j++)
        {
            tmp = tmp / 2;
        }
        tmp = (tmp & 1);
        int tmpy = tmp;
        if (tmpx == tmpy)
        {
            continue;
        }
        else if (tmpx == 1)
        {
            tmp = 1;
            for (int j = 0; j < i; j++)
            {
                tmp *= 2;
            }
            x -= tmp;
            ans += tmp;
        }
        else
        {
            break;
        }
    }
    ans = ans + y - x;
    printf("%d\n", ans);
}
int main(void)
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        solve();
    }
    return 0;
}