#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int a[N];
signed main(void){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n ,m ;cin >>n>>m;
	for(int i = 0 ;i <  n ;++i) cin >> a[i];
	sort(a,a+n);
	int res =0;
	for(int i = n-1 ; m > 0; i-- ){
		m-=a[i];
		res++;
	}
	cout << res;
	return 0;
}