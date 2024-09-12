#include <bits/stdc++.h>
using namespace std;
void solve(){
	int m , n;
	cin >> m >> n ;
	int mx1 = 10001;
	int mx2 = 10001;
	while(m--){
		int tmp;
		cin >> tmp;
		int tmp_f ;
		int tmp_c = fabs(tmp);
		while(tmp_c > 0 ){
			tmp_f = tmp_c;
			tmp_c/=10;	
		}
		if(tmp_f == n){
			if(mx1 == 10001){
				mx1 = tmp;
			}else if(mx2 == 10001){
				mx2 = tmp;
			}else if(mx1 <= tmp ){
				mx2 = mx1;
				mx1 = tmp;
			}else if(mx2 < tmp ){
				mx2 = tmp;
			}
		}
	}
	if(mx1 == 10001 and mx2 == 10001){
		cout << "NULL" << '\n';
	}else if(mx2 == 10001){
		cout << mx1 << '\n';
	}else{
		cout << mx1+mx2 <<'\n';
	}
	
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