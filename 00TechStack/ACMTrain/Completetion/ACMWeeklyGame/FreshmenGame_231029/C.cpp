#include <bits/stdc++.h>
using namespace std;
int a[101];
int run(){
	int l;
	cin>>l;
	int sam,flag = 1,pos = 1;
	cin>>a[0];
	sam = a[0];
	for(int i = 1;i < l;i++){
		cin>>a[i];
		if(a[i] != sam ) pos = i+1;	
		if(i==1 && a[1] != a[0]){ 
			flag = 0;
			continue;
		}
		if(flag == 0){
			if(a[2] == a[0]){
				pos = 2;
			}
			else{
				sam = a[1];
				pos = 1;
			}
			flag = 0;
		}
	
	}
	
	return pos; 
}
int main(void){
	
	int t;
	cin>>t;
	while(t--){
		cout<<run()<<'\n';
	}
	return 0;
	
}