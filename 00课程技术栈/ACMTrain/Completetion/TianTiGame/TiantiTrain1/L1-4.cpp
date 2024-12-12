#include <bits/stdc++.h>
using namespace std ;

void run(){
	int low ,diff ,cot =0 ;
	
	int a[4] = {0};
	
	int p_mx = 0 ;
	for(int i = 0 ; i < 4; i++) {
		cin >> a[i];
		p_mx = (a[i] > a[p_mx] ? i : p_mx);
	}
	cin >> low >> diff;
	int ans = -1;
	for(int i = 0 ; i < 4 ; i++) {
		if(a[p_mx] - a[i] > diff) {
			cot ++;
			ans = i;
		}
		else if(a[i] < low){
			cot ++;
			ans = i;
		}
	}
	
	if( cot == 0) {
		cout << "Normal";
		
	}else if(cot == 1){
		cout << "Warning: please check #" << ans+1 << "!";
	}else {
		cout << "Warning: please check all the tires!";
	}
	return ;
}
int main(){
	run();
	return 0;
} 