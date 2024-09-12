#include <bits/stdc++.h>
using namespace std ;

void run(){
	vector<string > s;
	
	while(true){
		string now ;
		getline(cin,now);
		if(now == ".") break;
		s.push_back(now);
	}
	
	int cot = 0 ;
	int fir = -1;
	
	string chg = "chi1 huo3 guo1";
	
	for(int i = 0 ; i < s.size() ; i++ ) {
		for(int j = 0 ; j < s[i].size() ; j++) {
			if(s[i][j] == 'c'){
				for(int k = 0 ; k < chg.size() ; k++){
					if(k + j >= s[i].size() ) break;
					if(s[i][j+k] != chg[k]) break;
					if(k == chg.size() - 1){
						cot++;
						if(fir == -1) fir = i+1;
					}
				}
			}		
		}
	}
	
	cout <<s.size() <<endl;
	if(cot == 0) cout <<"-_-#" ;
	else cout << fir << ' '<<cot;
	
	return ;
}
int main(){
	run();
	return 0;
} 