#include <bits/stdc++.h>
using namespace std;


void run(){
	int n ;
	cin >> n;
	getchar();
	map<string,vector<string> > mp;
	for(int i = 0 ; i < n ; i ++){
		string jz;
		getline(cin,jz);
		string sy;
		for(int j = 0 ; j < jz.size() ; j++){
			if(j==0){
				sy += jz[0];
			}
			if(jz[j] ==' ' and j != jz.size()-1){
				sy += jz[j+1];
			}
		}
		mp[sy].push_back(jz);
	}
	
	int m ;
	cin >> m;
	getchar();
	for(int i = 0 ; i < m ; i++){
		string sy;
		getline(cin,sy);
		string mm;
		for(int j = 0 ; j < sy.size(); j++){
			if(j == 0){
				mm += sy[0];
			}
			if(sy[j] ==' ' and j != sy.size()-1){
				mm += sy[j+1];
			}
		}
		
		if(mp.count(mm) != 0){
			cout << mp[mm][0];
			for(int j = 1 ; j < mp[mm].size() ; j++){
				cout << "|" << mp[mm][j];
			}
		}else{
			cout << sy;
		}
		cout << endl;
	}
}
int main(){
	run();
	return 0;
}
