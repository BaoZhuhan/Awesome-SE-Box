#include <bits/stdc++.h>
using namespace std;

int main()
{
    char str[100];
    int i = 0;
    while ((str[i] = getchar()) != '\n')
    {
        if (str[i] >= 'A' and str[i] <= 'Z')
        {
            str[i] = (char)('Z' - str[i] + 'A');
        }
        i++;
    }

    str[i] = '\0';

    for (i = 0; str[i] != '\0'; i++)
    {
        printf("%c", str[i]);
    }
    return 0;
}