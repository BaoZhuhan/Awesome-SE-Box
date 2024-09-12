#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int n = 2e5 + 5 ;
void solve(){
	int n ,m ;
	cin >> n >> m;
	string str;
	cin >> str;
	int res = n;
	map<char , int> mp;
	for(int i = 0 ; i < n ; i ++){
		if(mp.count(str[i]) == 0){
			mp.insert({str[i],1});
		}else{
			if(mp[str[i]] == 1){
				mp[str[i]]--;
				res -= 2;
			}else{
				mp[str[i]]++;
			}
		}
	}
	if(res <= m + 1){
		cout << "YES\n";
	}else{
		cout << "NO\n";
	}
	
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