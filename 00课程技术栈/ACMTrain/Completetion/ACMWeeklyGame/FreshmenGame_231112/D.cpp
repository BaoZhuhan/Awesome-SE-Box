#include <bits/stdc++.h>
using namespace std;
const int N=1005;
int a[N];
signed solve0(int n){
	int sum = 0;
	for(int i = 0 ; i < n ;++i){
		if(i % 2 == 1){
			if(a[i] == 0){
			sum++;
			}
		}
		else {
			if(a[i] == 1) {
			sum++;
			}
		}
	}
	
	return sum;
}
signed solve1(int n){
	int sum = 0;
	for(int i = 0 ; i < n ;++i){
		if(i % 2 == 1){
			if(a[i] == 1){
				sum++;
			}
		}
		else {
			if(a[i] == 0) {
				sum++;
			}
		}
	}
	return sum;
}
signed main(void){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n ; cin >> n;
	if(n == 0){
		cout << '-1';
		return 0;
	}
	char tmp;
	for(int i = 0 ;i < n  ;i++){
		cin >> tmp;
		a[i] = (int)(tmp- '0');
	}
	int sum0 = 0,sum1 = 0;
	sum0 = solve0(n);
	sum1 = solve1(n);
	if(sum1 < sum0) cout << sum1 ;
	else cout << sum0;
	return 0;
}