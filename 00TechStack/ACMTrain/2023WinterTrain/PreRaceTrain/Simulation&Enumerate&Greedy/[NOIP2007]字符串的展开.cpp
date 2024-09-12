#include <bits/stdc++.h>
using namespace std;

int p1, p2, p3;
string origin;
string ans;
string boundary = "0aA9zZ";

void exp(char begin, char end)
{
    begin++;
    end--;
    if (p3 == 1)
    {
        for (char i = begin; i <= end; i++)
        {
            if (p1 == 3)
            {
                for (int j = 0; j < p2; j++)
                {
                    ans += '*';
                }
            }
            else if (i >= '0' and i <= '9')
            {
                for (int j = 0; j < p2; j++)
                {
                    ans += i;
                }
            }
            else
            {
                if (p1 == 1 and (i > 'A' and i < 'Z'))
                {
                    for (int j = 0; j < p2; j++)
                    {
                        ans += (i - 'A' + 'a');
                    }
                }
                else if (p1 == 2 and (i > 'a' and i < 'z'))
                {
                    for (int j = 0; j < p2; j++)
                    {
                        ans += (i - 'a' + 'A');
                    }
                }
                else
                {
                    for (int j = 0; j < p2; j++)
                    {
                        ans += i;
                    }
                }
            }
        }
    }
    else
    {
        for (char i = end; i >= begin; i--)
        {
            if (p1 == 3)
            {
                for (int j = 0; j < p2; j++)
                {
                    ans += '*';
                }
            }
            else if (i >= '0' and i <= '9')
            { // bug 如果数字大于十

                for (int j = 0; j < p2; j++)
                {
                    ans += i;
                }
            }
            else
            {
                if (p1 == 1 and (i > 'A' and i < 'Z'))
                {
                    for (int j = 0; j < p2; j++)
                    {
                        ans += (i - 'A' + 'a');
                    }
                }
                else if (p1 == 2 and (i > 'a' and i < 'z'))
                {
                    for (int j = 0; j < p2; j++)
                    {
                        ans += (i - 'a' + 'A');
                    }
                }
                else
                {
                    for (int j = 0; j < p2; j++)
                    {
                        ans += i;
                    }
                }
            }
        }
    }
}

void simulate()
{
    cin >> p1 >> p2 >> p3;
    cin >> origin;
    int n_o = origin.size();
    bool lastflag = true;
    for (int i = 0; i < n_o - 1; i++)
    {
        bool flag = false;
        if (origin[i + 1] == '-')
        {
            if ((i != n_o - 2) and (origin[i + 2] > origin[i]))
            {
                for (int m = 0; m < 3; m++)
                {
                    if ((origin[i] >= boundary[m]) and (origin[i + 2] <= boundary[m + 3]))
                    {
                        flag = true;
                    }
                }
            }
        }
        ans += origin[i];
        if(flag == true)
        {
            if ((i + 3) == n_o)
            {
                lastflag = false;
            }
            exp(origin[i], origin[i + 2]);
            ans += origin[i + 2];
            i+=2;
        }
    }
    if(lastflag)
    {
        ans += origin[n_o-1];
    }
    cout << ans;
}

int main()
{
    int T = 1;
    while (T--)
    {
        simulate();
    }
    return 0;
}