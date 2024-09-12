#include <bits/stdc++.h>
using namespace std;
int run(){
	int x,y;
	cin>>x>>y;
	if(x == y) cout<<'0'<<'\n';
	else if(x > y){
		if((x-y)%2 == 0) cout<<'1'<<'\n';
		else cout<<'2'<<'\n';
	}
	else{
		if((y-x)%2 == 1) cout<<'1' <<'\n';
		else cout<<'2'<<'\n';
	}
	return 0;
}
int main(void){	
	int t;
	cin>>t;
	while(t--){
		run();
	}
	return 0;
}