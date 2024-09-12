#include <bits/stdc++.h>
using namespace std ;

void run(){
	int n;
	cin >> n;
	double ans = 0 ;
	
	for(int i = 0 ; i < n ; i++){
		double tmp ;
		cin >> tmp;
		ans += (1.0/tmp);
	}
	ans /= n;
	ans = 1.0/ans;
	printf("%.2lf" , ans );
	return ;
	
}
int main(){
	run();
	return 0;
} 