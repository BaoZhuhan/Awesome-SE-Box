#include <bits/stdc++.h>
using namespace std ;

void run(){
	int n , m , s;
	cin >> n >> m >> s;
	getchar();
	vector<deque<char> > a(n);
	
	for(int i = 0 ; i < n ; i ++){
		string s;
		getline(cin,s);
		for(int j = 0 ; j < m ; j++){
			a[i].push_back(s[j]);
		}
	}
	
	vector<int> cz;
	int tmp ;
	cin >> tmp;
	while(tmp!= -1){
		cz.push_back(tmp);
		cin >> tmp;
	}
	
	string ans = "";
	stack<char> kuang;
	
	for(int i = 0 ; i < cz.size() ; i++){
		if(cz[i] == 0 and kuang.size() != 0){
			ans += kuang.top();
			kuang.pop();
		}
		else{
			if(kuang.size() == s){
				ans += kuang.top();
				kuang.pop();
			}
			if(a[cz[i]-1].size() != 0){
				kuang.push(a[cz[i]-1][0]);
				a[cz[i]-1].pop_front();
			}
		
		}
	}
	
	cout << ans;
}
int main(){
	run();
	return 0;
}