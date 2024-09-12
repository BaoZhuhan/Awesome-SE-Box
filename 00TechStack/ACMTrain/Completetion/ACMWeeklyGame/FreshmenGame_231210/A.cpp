#include <bits/stdc++.h>
using namespace std;
void solve(){
	int res = 1;
	int n , m ;
	cin >> n >> m ;
	while(n--){
		int tmp;
		cin >> tmp ;
		if(tmp > m){
			res++;
		}
	}
	cout << res << '\n';
	
}
int main(void){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	int T ;
	cin >> T ;
	while(T--){
		solve();
	}
	return 0;
}