#include <bits/stdc++.h>
using namespace std ;

void run(){
	double x,y,z;
	cin >> x >> y >> z;
	
	double ans = 0;
	if(y == 0 ) ans = x*2.455;
	else ans = x*1.26;

	 
	printf("%.2lf " , ans);
	ans = ans / z;
	
	if(ans > 1) cout << "T_T";
	else cout << "^_^";
	
	
}
int main(){
	run();
	return 0;
} 
