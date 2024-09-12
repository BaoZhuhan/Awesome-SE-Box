#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n ;
	cin >> n;
	set<int> s;
	int res = 0;
	for(int i = 0 ; i < n ; i++){
		int tmp ; cin >> tmp;
		if(s.count(tmp) == 0){
			res++;
			s.insert(tmp);
		}	
	}
	cout << res ;
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	solve();
	
	return 0;
}