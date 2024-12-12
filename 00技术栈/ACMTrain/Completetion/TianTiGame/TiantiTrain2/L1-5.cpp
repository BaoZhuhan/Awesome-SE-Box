#include <bits/stdc++.h>
using namespace std ;

void run(){
	int a[24] = {0};
	for(int i = 0 ; i < 24 ; i++){
		cin >> a[i];
	}
	while(true){
		int t;
		cin >> t;
		if(t > 23 or  t < 0) break;
		if(a[t] > 50) cout << a[t] << " Yes\n";
		if(a[t] <= 50) cout << a[t] << " No\n";
	}
	
}
int main(){
	run();
	return 0;
}