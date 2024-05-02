#include <bits/stdc++.h>
using namespace std;

int main() {
    //sorry , i am training for "LanQiao" competition so i cheat now;
    int  n;
    cin >> n;
    vector<int> a( n );
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int t;
    cin >> t;
    for (int i = 0; i < n; i++) {
        if (a[i] == t) {
            for (int j = 0; j < n - 1; j++) {
                cout << a[j] << " ";
            }
            cout << a[n - 1];
            return 0;
        }
    }

    a.push_back( t );
    sort( a.begin(), a.end() );
    for (int j = 0; j < n; j++) {
        cout << a[j] << " ";
    }
    cout << a[n];
    return 0;
}