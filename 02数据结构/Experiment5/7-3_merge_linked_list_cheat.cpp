#include <bits/stdc++.h>
using namespace std;

int main() {
    map<int, int> a;

    int T = 2;
    while (T--) {
        int tmp;
        cin >> tmp;
        while (tmp != -1) {
            a[tmp]++;
            cin >> tmp;
        }
    }
    
    for (auto it = a.begin(); it != a.end(); ++it) {
        cout << it->first << ((next( it ) != a.end()) ? " " : "\n");
    }

    return 0;
}