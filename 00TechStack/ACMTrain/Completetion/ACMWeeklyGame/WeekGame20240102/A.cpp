#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
void solve(){
	string now;
	cin >> now;
	int res = 0;
	int p = 1;
	for(int i = 0; i < 4 ; i++){
		int tmp = now[i] - '0';
		if(tmp == 0) {
			tmp = 10;
		}
		if(p == tmp){
			res++;
		}else{
			res += fabs(tmp - p);
			p = tmp;
			res++;
		}
	}
	cout << res << endl;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		solve();
	}
	return 0;
}