#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N = 1e5+5;
#define int long long

void solve(){
	double n;
	cin >> n;
	if(n == 1){
		cout << 0 << endl;
	}
	else{
		int tmp = (sqrt((double)n));
		int res;
		if((( 1 + 1*(tmp - 1) ) + ( tmp - 1 ) *( 1 + 1*(tmp - 1) ) )>= n){
			res = tmp*2 - 2;
		}else if((( 1 + 1*(tmp - 1) ) + ( tmp) *( 1 + 1*(tmp - 1) ) )>= n){
			res = tmp*2 - 1;
		}else{
			res = tmp*2;
		}
		cout << res << endl;
	}
	
}
signed main(void){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		solve();
	}
	return 0;
}