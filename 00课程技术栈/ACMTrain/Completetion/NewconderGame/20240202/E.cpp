#include <bits/stdc++.h>
using namespace std;

struct node {
    int score ; 
    int index ;
};

bool cmp (node x , node y){
    return x.score > y.score ; 
}

void solve(){
    //不要忘记main函数的T
    int n , m  ;cin >> n >> m ; 
    vector<node> cxk(n + 1) ;
    for(int i = 1 ; i <= n ; i++){
        node now ; 
        now.index = i ;
        cin >> now.score ; 
        cxk[i] = now;
    }
    for(int i = 1 ; i <= m ; i++){
        int u , v ;  cin >> u >> v ;
        if( u == 1 or v == 1){
            cxk[1].score += 3;
        }else{
            if(cxk[u].score < cxk[v].score){
                cxk[u].score += 3;
            }else if(cxk[u].score == cxk[v].score){
                cxk[u].score += 1;
                cxk[v].score += 1;
            }else{
                cxk[v].score += 3;
            }
        }
    }

    sort(cxk.begin() , cxk.end() , cmp);
    for(auto i : cxk) cout << "name-->" << i.index << "score-->" << i.score << endl; 
    int rank = 0;
    for(int i = 0 ; ; i++){
        if(i == 0) rank = 1;
        else if(cxk[i].score < cxk[i-1].score) rank = i+1;
        if(cxk[i].index == 1){
            cout << rank << '\n';
            return;
        }
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}