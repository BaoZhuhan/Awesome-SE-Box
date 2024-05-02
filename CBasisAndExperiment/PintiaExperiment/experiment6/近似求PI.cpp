#include <bits/stdc++.h>
using namespace std;
double odd_factorial(int t)
{
    double res = 1;
    for (int i = 1, j = 3; i <= t; i++, j += 2)
    {
        res *= j;
    }
    return res;
}
double factorial(int t)
{
    double res = 1;
    for (int i = 1; i <= t; i++)
    {
        res *= i;
    }
    return res;
}
signed main(void)
{
    double eps;
    cin >> eps;
    double last = 1, res = 1;
    for (int i = 1; last >= eps; i++)
    {
        last = factorial(i) / odd_factorial(i);
        res += last;
        // cout << factorial(i) << ' ' << odd_factorial(i) << ' ' << last << ' ' << res << ' ' << '\n';
    }
    printf("PI = %.5lf", res * 2);
    return 0;
}