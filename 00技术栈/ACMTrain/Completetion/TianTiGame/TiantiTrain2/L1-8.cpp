#include <bits/stdc++.h>
using namespace std ;

vector<int> a(2);
int n ;
void add(int tmp) {
	stack<int> s;
	bool flag = false;
	if(tmp < 0) {
		flag = true;
		tmp = -1*tmp;
	}

	while(tmp>0){
		s.push(tmp - tmp/10*10);
		tmp /= 10;
	}
	
	while(!s.empty()){
		if(a.size() > n) return;
		if(flag == true){
			a.push_back(-1 * s.top());
//			flag = false;
		}else{
			a.push_back(s.top());
		}
		s.pop();
	}

}
void run(){
	

	cin >> a[0] >> a[1] >> n;
	for(int i = 1 ; a.size() < n; i++){
		int tmp = a[i]*a[i-1];
		add(tmp);
	}
	
	for(int i = 0 ; i < n - 1; i ++) {
		cout << a[i] << ' ';
	}
	cout << a[n-1];
	return ;
	
}
int main(){
	run();
	return 0;
}