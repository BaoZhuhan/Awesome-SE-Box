#include <bits/stdc++.h>
using namespace std;
struct node{
	int r;
	int s;
	int p;
};

void solve(){
	int n;
	cin >> n ;
	node a,b; 
	cin >> a.r >> a.s >> a.p;
	cin >> b.r >> b.s >> b.p;
	int nr = min(a.r,b.s);
	int ns = min(a.s,b.p);
	int np = min(a.p,b.r);
	int res2 =nr + ns + np;
		
	int sum = 0;
	sum += min(b.p + b.r , a.r);
	sum += min(b.s + b.p , a.p);	
	sum += min(b.r + b.s , a.s);
	int res1 = n - sum;
	cout << res1 << ' ' << res2;
		
}

int main(void){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T = 1;
//	cin >> T;
	while(T--){
		solve();
	}
	return 0;
}