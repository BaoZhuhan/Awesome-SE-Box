#include <bits/stdc++.h>
using namespace std ;

void run(){
	int n , m;
	cin >> n >> m;
	
//	vector<string> s;
	vector<int> a;
	for(int i = 0 ; i < m ; i++){
		string now;
		cin >> now;
		int ans = 1;
		for(int j = 0 ; j < now.size() ; j++) {
			if(now[j] == 'n'){
				ans += pow(2,now.size() - j -1);
			}
		}
		a.push_back(ans);
	}
	
	for(int i = 0 ; i < a.size() ; i++ ){
		cout << a[i] <<endl;
	}
	return ;
}
int main(){
	run();
	return 0;
} 