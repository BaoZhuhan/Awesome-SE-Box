#include <bits/stdc++.h>
using namespace std;

typedef struct node {
    int start;
    int finish;
} node;

bool cmp(struct node a, struct node b) {
    return a.finish < b.finish;
}

int main() {
    int n;
    cin >> n;
    vector<struct node> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].start >> a[i].finish;
    }
    sort(a.begin(), a.end(), cmp);
    int ans = 0;
    int time = a[0].start;
    for (int i = 0; i < n; i++) {
        // cout << a[i].start << " " << a[i].finish << " " << time << '\n';
        if (a[i].start >= time) {
            ans++;
            time = a[i].finish;
        }
    }
    cout << ans;
    return 0;
}