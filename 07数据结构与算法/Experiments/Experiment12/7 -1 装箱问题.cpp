#include <bits/stdc++.h>
using namespace std;

struct node {
    int weight;
    int loc;
};

int main() {
    int n;
    cin >> n;
    vector<struct node> a(n);
    vector<int> b(n, 0);
    int res = 0;
    // for(int i = 0 ; i < n ; i++) cin >> a[i].weight;
    for (int i = 0; i < n; i++) {
        cin >> a[i].weight;
        for (int j = 0; j < n; j++) {
            if (b[j] + a[i].weight <= 100) {
                if (b[j] == 0)
                    res++;
                b[j] += a[i].weight;
                a[i].loc = j + 1;
                break;
            }
        }
        cout << a[i].weight << " " << a[i].loc << "\n";
    }
    cout << res;
    return 0;
}