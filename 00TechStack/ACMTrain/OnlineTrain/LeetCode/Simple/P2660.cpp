#include <bits/stdc++.h>
using namespace std;

vector<int> &player1;
vector<int> &player2;

class Solution
{
public:
    int isWinner(vector<int> &player1, vector<int> &player2)
    {
        int sorce1 = 0, sorce2 = 0;
        int n = player1.size();
        for (int i = 0; i < n; i++)
        {
            sorce1 += player1[i];
            sorce2 += player2[i];
            if (i == 0)
            {
                continue;
            }
            else if (i == 1)
            {
                if (player1[0] == 10)
                {
                    sorce1 += player1[i];
                }
                if (player2[0] == 10)
                {
                    sorce2 += player2[i];
                }
            }
            else
            {
                if (player1[i - 1] == 10 or player1[i - 2] == 10)
                {
                    sorce1 += player1[i];
                }
                if (player2[i - 1] == 10 or player2[i - 2] == 10)
                {
                    sorce2 += player2[i];
                }
            }
        }
        if (sorce1 > sorce2)
        {
            return 1;
        }
        else if (sorce1 == sorce2)
        {
            return 0;
        }
        else
        {
            return 2;
        }
    }
};
int main(void)
{
    return 0;
}