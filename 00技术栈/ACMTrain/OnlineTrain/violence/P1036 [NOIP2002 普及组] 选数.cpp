#include <bits/stdc++.h>
using namespace std;

bool isprime(int a){
    for(int i = 2 ; i * i <= a ; i++) {if(a%i == 0) { return false ;}}
    return true;
}

vector<int> a(25,0);

int n , k ; 
long long ans = 0;

void dfs(int m , int sum , int startx) {
    if(m == k) {
        if(isprime(sum)) {ans++; }
        return ;
    }
    for(int i = startx ; i < n ; i++) {dfs(m+1 ,sum+a[i] , i+1); }
    return;
}
void run(){
    cin >> n >> k;
    for(int i = 0 ; i < n ; i++) { cin >> a[i] ;}
    dfs(0,0,0);
    cout << ans ;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) {run();}
    return 0;
}