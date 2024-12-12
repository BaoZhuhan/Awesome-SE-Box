#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

void solve(){
	int n , x;
	cin >> n >> x;
	if(n == 1 or n == 2){
		cout << 1 << endl;
	}else{
		if((n -2) % x == 0){
			cout << ((n -2) /x )+1 << endl;
		}else{
			cout << ((n -2) /x )+2 << endl;
		}
	}
}

int main(void){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		solve();
	}
	return 0;
}