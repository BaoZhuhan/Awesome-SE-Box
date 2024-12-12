#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,a[N],ans[N];
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	stack<int> stk;
	for(int i=n;i>=1;i--){
		while(stk.size() and stk.top()<=a[i])stk.pop();
		stk.push(a[i]);
		ans[i]=stk.size();
	}	
	for(int i=1;i<=n;i++)cout<<ans[i]<<"\n";
}
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T=1;
	for(int i=1;i<=T;i++){
		solve();
	}
}