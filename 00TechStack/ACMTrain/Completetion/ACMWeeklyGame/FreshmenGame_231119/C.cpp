#include <bits/stdc++.h>
using namespace std;
signed slove(int n){
    vector<int> a(n);
    int minn = INT_MAX , tmp;
    for(int i = 0 ; i < n ; ++i) cin >> a[i];
    for(int i = 1 ; i < n ; ++i){
        if(a[i] < a[i-1]){
            return 0;
        }
        else{
            tmp = a[i] - a[i-1];
            if(tmp < minn) minn = tmp;
            //cout << "tmp-->" << tmp << endl;
        }
    }
    //cout << "min-->" << min << endl;
    return (minn/2)+1 ; 
    
}
signed main(void){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t ; cin >> t;
    while(t--){
        int n ; cin >>n;
        cout << slove(n) << '\n';
    }
    return 0;
}