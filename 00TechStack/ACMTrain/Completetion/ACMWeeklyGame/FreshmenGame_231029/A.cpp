#include <bits/stdc++.h>
using namespace std;
int run(){
	char c;
	cin>>c;
	string a = "Yes";
	int flag = 0;
	int i = 0;
	for( i = 0; i < 3; i++){
		if(c == a[i])
		{
			flag = 1;
			break;
		}
	}
	for(int j =i+1;;j++){
		if(j == 3) j = 0;
		scanf("%c",&c);
		if(c == '\n' || c == ' ') break;
		if(c != a[j]){
			flag = 0;
		}
	}
	if(flag == 0) cout<<"NO"<<'\n';
	else cout<<"YES"<<'\n';	
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