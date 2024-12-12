#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
set<int> a;
void solve(){
	int t;
	cin >> t;
	int res = 0;
	int sum = 0;
	a.insert(0);
	for(int i = 0; i < t ; i++){
		int tmp ; 
		cin >> tmp;
		sum += tmp;
		if(a.count(sum) == 1){
			res++;
		}else{
			a.insert(sum);
		}
	}
	cout << res;	
}
signed main(void){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T = 1;
//	cin >> T;
	while(T--){
		solve();
	}
	return 0;
}
