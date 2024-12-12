#include <bits/stdc++.h>
using namespace std ;

bool cmp(int a , int b ){
    return (a > b);
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    vector<int> a;
    int n ,m ; cin >> n >> m ;
    for(int i = 0 ; i < n ; i++) {
        int tmp ;cin >> tmp; 
        a.push_back(tmp);
    }
    sort(a.begin(),a.end(),cmp);
    for(int i = 0 ; i < m-1 ; i++){
        cout << a[i] << ' ';
    }
    cout << a[m-1] << '\n';
    return 0;
}