#include <bits/stdc++.h>
using namespace std;


void run(){
	int n ;
	cin >> n;
	int a[n];
	for(int i = 0 ; i< n ; i++){
		cin >> a[i];
	}
	
	int t;
	cin >> t;
	
	for(int i = 0 ; i < t ; i++){
		bool flag = true;
		bool cl = false;
		
		for(int j = 0 ; j < n ; j++){
			int c;
			cin >> c;
			
			if(c == 0){
				continue;
			}else{
				if(c == a[i]){
					cl = true;
				}else {
					cl = true;
					flag = false;
				}
			}
		}
		
		cout << cl << " " << flag << endl; 
		
		if(cl == true and flag == true){
			cout << "Da Jiang!!!" << endl;
		}else {
			cout << "Ai Ya" << endl;
		}
	}
}
int main(){
	run();
	return 0;
}
