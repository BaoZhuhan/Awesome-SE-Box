#include <bits/stdc++.h>

using namespace std;

const long long inf = 1e9 + 1;

long long power(int a , int b ){
    int res = 1;
    for(; b ; b >>= 1){
        if(b & 1){
            if(fabs((long long)(res) * a) > inf) return inf;
            res *= a;
        }
        if(fabs((long long)(a) *  a  > inf )) a = inf ;
        a *= a;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0) , cin.tie(0);

    int n , q ; cin >> n >> q;
    vector<int> a(n);
    map<int , int > cnt;
    for(int i = 0 ; i < n ; i++) {
        cin >> a[i] ; 
        cnt[a[i]]++;
    }
    sort(a.begin() , a.end());
    
}

