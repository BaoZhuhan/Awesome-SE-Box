#include <bits/stdc++.h>
using namespace std;

int m, n, k;

void run() {
    queue<int> q;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        q.push( t );
    }

    stack<int> s;
    for (int i = 1; i <= n; i++) {
        if(s.size() <m ) s.push( i );
        else break;
        while (!s.empty() and !q.empty() and s.top() == q.front()) {
            q.pop();
            s.pop();
        }
    }

    if (!q.empty() or !s.empty()) cout << "NO\n";
    else cout << "YES\n";

    return;
}

int main() {
    cin >> m >> n >> k;
    while (k--) {
        run();
    }
    return 0;
}