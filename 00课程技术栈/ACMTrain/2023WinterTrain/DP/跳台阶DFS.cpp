#include <bits/stdc++.h>
using namespace std;
const int N = 20;
stack<int> s;
int dfs_stack(int t){
    s.push(1);
    s.push(2);
    int res = 0;
    if(t == 1 or t == 2){
        return t;
    }
    while(!s.empty()){
        int now = s.top();
        s.pop();
        if(now == t){
            res++;
            continue;
        }else if(now > t){
            continue;
        }
        s.push(now+1);
        s.push(now+2);
    }
    return res;
}

int dfs(int t){
    if(t == 1){
        return 1;
    }else if(t == 2){
        return 2;
    }else{
        return dfs(t - 1) + dfs(t -2);
    }
}

void solve(){
    int t;
    cin >> t;
    int res = dfs(t);
    cout << res;
}
int main(){
    int T = 1;
    while(T--){
        solve();
    }
    return 0;
}