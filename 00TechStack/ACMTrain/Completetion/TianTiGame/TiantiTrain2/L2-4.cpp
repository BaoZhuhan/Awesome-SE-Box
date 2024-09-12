#include <bits/stdc++.h>
using namespace std ;

void run(){
	int n , m ;
	cin >> n >> m ;
	
	vector<vector<int> > jq;
	int cd[105] = {0};
	
	
	vector<int> bb(0);
	jq.push_back(bb);
	for(int i = 1; i <= n ; i++){
		int tn;
		cin >> tn;
		vector<int> aa(tn+5);
		for(int j = 1; j <= tn ; j++){
			cin >> aa[j];
		}
		jq.push_back(aa);
	}
	
	int loc = 1;
	for(int i = 0 ; i < m ; i++){
		int cnt  , tar;
		cin >> cnt >> tar;
		if(cnt == 0){
			loc = jq[loc][tar];
		}else if(cnt == 1){
			cd[tar] = loc;
			cout << loc << endl;
		}else if(cnt == 2){
			loc = cd[tar];
		}
	}
	cout << loc ;
}
int main(){
	run();
	return 0;
}