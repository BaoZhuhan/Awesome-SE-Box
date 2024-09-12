#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n , m;cin >> n >> m;
	int flag = 0 ;
	for(int i = 0 ; flag == 0 ;i++){
		if( n-1 >= 0 ){
			n-=1;
			continue;
		}
		else if( m-1 >= 0 ){
			m-=1;
			continue;
		}
		else {
			if (i%2 == 0) flag = 2;
			else flag = 1;
		}
	}
	if(flag == 1) cout << "Alice";
	else cout << "Bob";
	
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	solve();
	return 0;
}