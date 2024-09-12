#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n ; cin >> n ; 
    vector<int> col(n+1 , 0 );
    map<int , deque<int> > mp;
    set<int> s;
    int mx = 0 ;   // mx代表最大的mp[i] 的size
    for(int i = 1 ; i <= n ; i++ ){
        cin >> col[i];
        if(mp.count(col[i]) == 0){
            deque<int> now ; now.push_front(i);
            mp[col[i]] = now;
            s.insert(col[i]);
        }else{
            mp[col[i]].push_front(i);
        }
        if(mx < mp[col[i]].size()) mx = mp[col[i]].size() ; 
    }

    int ans = 0; 
    int mn = n; //mn代表当前准备到的最小的位置
    
    int colflag  = 0; 
    // int cnt = 1;
    // for(int i = 0 ; i < mx ; i++ ){
    //     for(pair<int, deque<int>> a : mp) {
    //         if(a.second.size() - 1 < i or a.second[i] <= n ) colflag += 1;
    //         mp.second
    //         if()
    //         if(a.second[i] < mn ) mn = a.second[i] ;
    //         if(colflag == mp.size()){
    //             n = mn ;
    //             ans++;
    //             colflag = 0;
    //         }

    //     }
    // }
    set<int> extflag;
    while(!mp.empty()) {
        for(auto i : s){
            if(colflag == s.size()){
                n = mn ;
                ans ++ ;
                colflag = 0;
            }
            if(mp[i].size() == 0 ){
                colflag += 1;
                extflag.insert(i);
                continue;
            }
            int now = mp[i].front();
            while(now > n){
                mp[i].pop_front();
                now = mp[i].front();
            }mp[i].pop_front();
            mn = now < mn ? now : mn;
            if(extflag.size() == s.size()){
                cout << ans << '\n' ;
                return ;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T ; cin >> T;
    while(T--) solve();
    return 0;
}