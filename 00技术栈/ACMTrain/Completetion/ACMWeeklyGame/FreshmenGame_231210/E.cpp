#include <bits/stdc++.h>
using namespace std;
void solve(){
	int n , d ;
	cin >> n >> d;
	string s;
	cin >> s;
	int p = 0 ;
	int flag = 1;
	int res = 0;
	while(flag == 1 and p != n-1){
		flag = 0 ;
//		cout << "come\n";
		for(int i = d ; i > 0 ;i--){
			if(s[p+i] == '1'){
				flag = 1;
				p = p+i;
				res++;
//				cout << res <<' '<< p  <<'\n'; 
				break;
			}
		}
	}
	if(flag == 1){
		cout << res;
	}else{
		cout << "-1";
	}
	
}
int main(void){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	int T =1 ;
	while(T--){
		solve();
	}
	return 0;
}