#include <bits/stdc++.h>
using namespace std;

void run(){
    int n ;
    cin >> n ;
    vector<int> a(n,0);
    vector<int> b(n,0);

    for(int i = 0 ; i < n ; i++) {
        cin >> a[i];
    }
    int mid = 0;
    for(int i = 0 ; i < n ; i++) {
        cin >> b[i];
        mid += b[i];
    }
    mid = mid / n ;

    int pa = 0;
    for(int i = 0 ; i < n ; i++ ) {
        if(fabs(a[pa]- mid) > fabs(a[i] - mid)) pa = i;
    }

    int ans = 1e9;
    int pb = 0;
    for(int i = 0 ; i < n ; i++ ) {
        if(fabs(b[pb] - a[pa]) > fabs(b[i] - a[pa])) pb = i;
    }

    swap(a[pa] , a[pb]);
    for(auto x : a) { cout << x << ' ' ;}
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) {run();}
    return 0;
}