#include <bits/stdc++.h>
using namespace std;
set<char> st;

int main(void)
{
    st.insert('A');
    st.insert('E');
    st.insert('I');
    st.insert('O');
    st.insert('U');

    int i = 0;
    char str[100];
    while ((str[i] = getchar()) != '\n')
        {
            i++;
        }
    str[i] = '\0';
    int res = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (st.count(str[i]) == 0 && str[i] >= 'A' && str[i] <= 'Z')
            res++;
    }
    cout << res;
    return 0;
}