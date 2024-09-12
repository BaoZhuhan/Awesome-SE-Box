#include <bits/stdc++.h>
using namespace std ;

void run(){
	int n ;
	cin >> n;
	int mn = INT_MAX , mx = -1*INT_MAX;
	int mnn = 1 , mxn = 1;
	for(int i = 0 ; i < n ; i++){
		int tmp;
		cin >> tmp;
		
		if(tmp < mn){
			mn = tmp;
			mnn = 1;
		}
		else if(tmp == mn ){
			mnn ++;
		}
		
		if(tmp > mx){
			mx = tmp;
			mxn = 1;
		}else if(tmp == mx ){
			mxn ++;
		}
	}

	cout << mn << " " << mnn << endl;
	cout << mx << ' ' << mxn << endl;
	
}
int main(){
	run();
	return 0;
}