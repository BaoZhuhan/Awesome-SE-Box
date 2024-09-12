#include <bits/stdc++.h>
using namespace std;
#define int long long 
int maxsum (vector<int> tmp , int n ){
    vector<int> sum(n+1);
    int ans = tmp[0]; 
    for(int i = 0 ; i <= n ; i++ ){
        if(sum[i-1] < 0 ){
            sum[i] = tmp[i];
        }else{
            sum[i] = sum[i-1] + tmp[i];
        }
        if(sum[i] > ans) ans = sum[i] ;
    }
    return ans;
}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n , k ;cin >> n >> k;
    vector<int> a(n+1 , 0);
    vector<int> sum(n+1 , 0);
    for(int i = 1 ; i <= n ; i ++ ){
        cin >> a[i]; 
    }
    for(int i = 0 ; i <= n ; i++) cout << a[i] << ' ' ;
    cout << endl; 
    int ans = maxsum(a , n); 
    if(k == 1) {
        for(int i = 1 ; i <= n - 1 ; i++){
            swap(a[i] , a[i+1]);
            ans = ans > maxsum(a , n) ? ans : maxsum(a , n) ;
            swap(a[i] , a[i+1]);
        }
    }
    cout << ans ; 
}

