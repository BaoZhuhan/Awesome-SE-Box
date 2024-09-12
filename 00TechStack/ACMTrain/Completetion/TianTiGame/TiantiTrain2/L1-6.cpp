#include <bits/stdc++.h>
using namespace std ;

void run(){
	int n , m ;
	cin >> n >> m;
	
	vector<string> a(n);
	vector<bool> b(n);
	getchar();
	
	for(int i = 0 ; i < n ; i++ ){
		getline(cin,a[i]);
	}
	
	for(int i = 0 ; i < n ; i++ ){
		b[i] = 0;
		for(int j = 0 ; j < a[i].size() ; j++){
	
			if(a[i][j] == 'q'){
				bool tflag = true;
				string c = "qiandao";
				for(int k = 0 ; k < 7 ; k++ ){
					if(a[i][j+k] !=  c[k]){
						tflag = false;
					}
				}
				if(tflag == true) {
					b[i] = 1;
				}
			}
			else if(a[i][j] == 'e'){
				bool tflag = true;
				string c = "easy";
				for(int k = 0 ; k < 4 ; k++ ){
					if(a[i][j+k] !=  c[k]){
						tflag = false;
						break;
					}
				}
				if(tflag == true) {
					b[i] = 1;
					break;
				}
			}
		}
		
	}
	int zl = 0;
	for(int i = 0 ; i < n ; i++){
		if(zl == m ){
			for(int j = i ; j < n ; j++){
				if(b[j] == false){
					cout << a[j];
					return ;
				}
			}
			cout << "Wo AK le"; 
			return;
		}
		
		if(b[i] == false ) zl++;
	}
	
	cout << "Wo AK le";
	return;
	
}
int main(){
	run();
	return 0;
}