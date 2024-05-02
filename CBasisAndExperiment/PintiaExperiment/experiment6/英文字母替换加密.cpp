#include <bits/stdc++.h>
using namespace std;
signed main(void)
{
    char tmp = '0';
    while (tmp != '\n')
    {
        tmp = getchar();
        if (tmp >= 'a' && tmp < 'z')
        {
            cout << (char)(tmp + 'B' - 'a');
        }
        else if (tmp == 'z')
        {
            cout << 'A';
        }
        else if (tmp >= 'A' && tmp < 'Z')
        {
            cout <<(char)(tmp + 'b' - 'A');
        }
        else if (tmp == 'Z')
        {
            cout << 'a';
        }
        else
        {
            cout << (char)tmp;
        }
    }
    return 0;
}