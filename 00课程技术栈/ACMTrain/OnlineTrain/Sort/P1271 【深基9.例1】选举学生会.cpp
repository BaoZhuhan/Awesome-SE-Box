#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5 ;

void run(){
    int n , m ; cin >> n >> m ;
    vector<int> a(m);
    for(int i = 0 ; i < m ; i++) {
        cin >> a[i];
    }
    sort(a.begin() , a.end());
    for(auto i : a) cout << i << ' ' ;
    return ;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    run();
    return 0;
}