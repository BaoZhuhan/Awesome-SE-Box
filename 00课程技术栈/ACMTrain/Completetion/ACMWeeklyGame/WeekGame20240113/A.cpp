#include <bits/stdc++.h>
using namespace std;
#define int long long 

int n,m,p,q,res=0;
int a[600][600];


void dfs(int x,int y,int p1,int q1){
	if(a[x][y]==1){
		q1++;
	}else{
		p1++;
	}
	if(x>n or y>m) return ;
	if(x==n && y==m && p1>=p && q1>=q){
		res=(res+1)%998244353;
	}
	dfs(x+1,y,p1,q1);
	dfs(x,y+1,p1,q1);
}
void solve(){
	res=0;
	cin>>n>>m>>p>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		} 
	} 
	dfs(1,1,0,0);
	cout<<res<<"\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T=1;//cin>>T;
	while(T--) solve();
	return 0;
}