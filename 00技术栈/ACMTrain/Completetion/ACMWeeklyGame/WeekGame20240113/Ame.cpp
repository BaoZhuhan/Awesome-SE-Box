#include <bits/stdc++.h>
using namespace std;
#define int long long 

struct node{
    int x;
    int y;
};

int p,q,res = 0; 
node tar;
map<node , int> memr;
int mp[600][600];

void dfs(int x,int y,int p1,int q1){
    if
    if(mp[x][y] == 1){
        q1++;
    }else{
        p1++;
    }
	if(x > tar.x or y > tar.y) return ;
	if(x==tar.x and y==tar.y and p1>=p and q1>=q){
		res=(res+1)%998244353;
	}
	dfs(x+1,y,p1,q1);
	dfs(x,y+1,p1,q1);
}
void solve(){
    res = 0;
    node now;
    cin >> now.x >> now.y >> p >> q; 
    tar = now;
    for(int i = 0 ; i <= tar.x ; i++){
        for(int j = 1 ; j <= tar.y ; j++ ){
             cin >> mp[i][j];
        }
    }
    node tmp;
    tmp.x = 1 ,tmp.y = 1;
    memr.insert(make_pair(tmp,1));
    dfs(1,1,0,0);
    cout << res << '\n' ;
    return;   
}
signed main(void){
    ios::sync_with_stdio(0),cin.tie(0);
    int T = 1;
    while(T--){
        solve();
    }
    return 0;
}