#include <bits/stdc++.h>
using namespace std ;

void run(){
	int n , m  , k;
	cin >> n >> m >> k;
	int ans = n -m*k;
	cout << (ans > 0 ? ans : 0);  
	
}
int main(){
	run();
	return 0;
}