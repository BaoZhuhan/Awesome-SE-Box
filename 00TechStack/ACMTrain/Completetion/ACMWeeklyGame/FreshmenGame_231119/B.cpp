#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;


signed solve(){
	int a , b ,c ;cin >> a >>b >>c;
	int sum1 = a+b;
	int sum2 = b+c;
	int sum3 = a+c;
	if(sum1 >=10 || sum2 >=10 || sum3>= 10) cout << "YES"<<'\n';
	else cout << "NO" <<'\n'; 
	return 0;
}
signed main(void){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t ;cin >> t ;
	for(int i = 0 ; i < t ; ++i){
		solve();
	}
	return 0; 
}