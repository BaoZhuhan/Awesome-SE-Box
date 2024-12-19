#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> a(1001);
int ans = 0;

void DFS(vector<int> choose, int value, int loc) {
    if (value == m) {
        ans++;
        vector<int> res;
        for (int i = 1; i <= loc; i++) {
            if (choose[i] == 1) {
                res.push_back(a[i]);
            }
        }
        for(int i = 0 ; i < res.size()-1 ; i++) {
            cout << res[i] << " ";
        }
        cout << res[res.size()-1] << "\n";
        return;
    }

    if (value > m or loc > n)
        return;
    
    choose[loc] = 1;
    DFS(choose, value + a[loc], loc + 1);

    choose[loc] = 0;
    DFS(choose, value, loc + 1);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cin >> m;
    vector<int> choose(1001);
    DFS(choose, 0, 1);
    if (ans == 0) {
        cout << "None";
    }
}
