#include<bits/stdc++.h>
using namespace std;


int cal(int x){
	int res = 1;
	while(x != 0){
		int t = x % 10;
		res *= t;
		x /= 10;
	}
	return res;
}

void run(){
	int a , b;
	cin >> a >> b;
	
	vector<int> ans;
	int t = 0;
	
	for(int i = a ; i <= b ; i ++){
		int tt = 0;
		int x = i;
		while(x >= 10){
			x = cal(x);
			tt++;
		}
		
		if(tt > t){
			t = tt;
			ans.clear();
			ans.push_back(i);
		}else if(tt = t){
			ans.push_back(i);
		}
	}
	
	cout << t << endl;
	for(int i = 0 ; i < ans.size()-1 ; i++){
		
		cout << ans[i] << " ";
	}
	cout << ans[ans.size()-1];
	
}

int main(){
	run();
	return 0;
} 
