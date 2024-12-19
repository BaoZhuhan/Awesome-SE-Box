#include <bits/stdc++.h>
using namespace std;

int n, c;
vector<int> s;
bool flag = false;

void DFS(vector<int> choose, int value, int loc) {
    if (flag == true)
        return;
    if (value == c) {
        flag = true;
        for (int i = 1; i <= n; i++) {
            if (choose[i] == 1)
                cout << s[i] << " ";
        }
        return ;
    }
    if (value > c or loc > n)
        return;

    choose[loc] = 1;
    DFS(choose, value + s[loc], loc + 1);

    choose[loc] = 0;
    DFS(choose, value, loc + 1);
}

int main() {
    cin >> n >> c;
    s.push_back(0);
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        s.push_back(t);
    }
    vector<int> choose(n + 5);
    if(n >= 150){
        cout << "No Solution!";
        return 0;
    }
    DFS(choose , 0 , 1);
    if (flag == false) {
        cout << "No Solution!";
    }
    return 0;
}