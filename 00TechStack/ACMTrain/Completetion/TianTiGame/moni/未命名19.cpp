#include<bits/stdc++.h>
using namespace std;

void run(){
	int n , m ;
	cin >> n >> m;
	vector<set<int> > a(n+1);
	for(int i =  1 ; i <= n ; i++){
		int t ;
		cin >> t;
		for(int j = 0 ;j < t ; j++){
			int jj ;
			cin >> jj;
			a[i].insert(jj);
		}
	}
	
	int T ;
	cin >> T;
	for(int i = 0 ; i < T ; i++){
		int x , y;cin >> x >> y;
		int cot = 0;
		for(int j = 0 ; j < n ; j++){
			if(a[j].count(x) and a[j].count(y)) cot++; 
		}
		cout << cot << endl; 
	}
}

int main(){
	run();
	return 0;
} 
