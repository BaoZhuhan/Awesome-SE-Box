#include <bits/stdc++.h>
#define int long long
using namespace std;
int t,a[2];
signed run(){
	memset(a , 0 ,sizeof(a));
	int sum[2] = {0,1}; 
	int n ,cot = 0; cin >> n ;
	while(n--){
		int tmp ; cin >> tmp ;
		if(tmp == 1) a[1]++;
		else a[0]++;
		sum[1] *= tmp;
	}
	sum[0] = a[1] - a[0];
	while(a[0] != 0 ) {
		if(sum[0] >=0 && sum[1] == 1) break;
		
		a[0]--;a[1]++;cot++;
		sum[0] = a[1] - a[0];sum[1]*=-1;
	}
	cout << cot << '\n' ;
	return 0;
}
signed main(void){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> t ;
	for(int i = 1 ; i <= t ; ++i ) {
		run();
	}
	return 0 ;
}