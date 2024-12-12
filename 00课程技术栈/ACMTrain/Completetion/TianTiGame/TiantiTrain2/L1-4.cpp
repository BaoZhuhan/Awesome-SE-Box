#include <bits/stdc++.h>
using namespace std ;

void run(){
	double n , m ;
	cin >> n >>m ;
	for(int i = 0 ; i < n ; i ++){
		double t;
		cin >> t;
		if(t < m ) printf("On Sale! %.1lf\n" ,t);
	}
	return;
}
int main(){
	run();
	return 0;
}