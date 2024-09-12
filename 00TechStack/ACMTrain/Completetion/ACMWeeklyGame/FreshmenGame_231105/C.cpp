#include <bits/stdc++.h>
#define int long long
using namespace std;
int t,a[5];
signed turn(){
	a[0] = a[1];
	a[1] = a[3];
	a[3] = a[4];
	a[4] = a[2];
	a[2] = a[0];
	return 0;
}
signed test() {
	int flag =  1;
	if(a[1] > a[2]) flag = 0;
	if(a[1] > a[3]) flag = 0;
	if(a[3] > a[4]) flag = 0;
	if(a[2] > a[4]) flag = 0;
	return flag;
}
signed run(){
	memset(a , 0 , sizeof(a));
	for(int i = 1 ; i <= 4 ; ++i) cin >> a[i] ;
	for(int i = 1 ; i <= 4 ; ++i) {
		if(test() == 1) {
			cout << "YES" << '\n';
			return 0;
		}
		else turn();
	}	
	cout << "NO" << '\n' ;
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