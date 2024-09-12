#include <bits/stdc++.h>
using namespace std;
struct node {
	int a1;
	int a2;
	int a3;
	int a4;
};
void solve(){
	int n , m; 
	cin >> n >> m;
	vector<node> a(n);
	bool flag = false;
	for(int i = 0 ;i < n ; i++){
		cin >> a[i].a1 >> a[i].a2 >> a[i].a3 >> a[i].a4;
		if(a[i].a2 == a[i].a3){
			flag = true; 
		}
	}
	if(m % 2 != 0){
		flag = false;
	}
	if(flag){
		cout << "Yes\n";
	}else{
		cout << "No\n";
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