#include <bits/stdc++.h>
using namespace std;
char a[6];
int run(){
	int sum1=0,sum2=0;
	for(int i = 0;i<6;i++){
		cin>>a[i];
		if(i<3) sum1+=(int)(a[i]-'0');
		else sum2+=(int)(a[i]-'0');
	}
	if(sum1==sum2) return 1;
	else return 0;

	
}
int main(void){
	
	int t;
	cin>>t;
	while(t--){
		if(run()) cout<<"YES"<<'\n';
		else cout<<"NO"<<'\n';
	}
	return 0;
}