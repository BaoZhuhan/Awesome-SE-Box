#include <bits/stdc++.h>
using namespace std ;

struct node {
	string name;
	string sfz;
	int hel;
	int time;
};

map<string , int> mp;
vector<vector<node> > a;
vector<node> ans1;
vector<node> ans2;
set<string> s;

int d , p;

bool cmp(node a ,node b){
	return a.time < b.time;
}

void run(){
	for(int i = 0 ; i < a.size() ; i++) {
		for(int j = 0 ; j < a[i].size() ;j++){
			if(mp[a[i][j].sfz] == -1){
//				cout << i << ' ' <<j <<endl;
				mp[a[i][j].sfz] = i;
				ans1.push_back(a[i][j]);
				if(a[i][j].hel == 1 and s.count(a[i][j].sfz) == 0){
					ans2.push_back(a[i][j]);
					s.insert(a[i][j].sfz);
				}
			}else{
				int day = mp[a[i][j].sfz] + p + 1;
				if(i >= day){ 
					mp[a[i][j].sfz] = i;
					ans1.push_back(a[i][j]);
					if(a[i][j].hel == 1 and s.count(a[i][j].sfz) == 0){
						ans2.push_back(a[i][j]);
						s.insert(a[i][j].sfz);
					}
				}
			}
			
			
		}
	}
	
	for(int i = 0 ; i < ans1.size() ; i++) {
		cout << ans1[i].name <<' ' <<ans1[i].sfz << endl;
	}
	for(int i = 0 ; i < ans2.size() ; i++) {
		cout << ans2[i].name <<' ' <<ans2[i].sfz << endl;
	}
	return ;
}
void unit(){
	cin >> d >> p;
	for(int i = 0 ; i < d ; i++ ){
		vector<node> aa;
		int tt , ss;
		cin >> tt >> ss;
		for(int j = 0 ; j < tt ; j++){
			node now;
			string time;
			cin >> now.name >>now.sfz >>now.hel >>time;
			
			if((now.sfz).size() != 18) continue;
			bool tmpflag = false;
			for(int i = 0 ; i < 18 ; i++ ){
				if(now.sfz[i] > '9' or now.sfz[i] < '0') {
					tmpflag = true;
					break;
				}
			}
			if(tmpflag) continue;
			
			int hh ,mm ;
			hh = int(time[0] - '0')*10 + int(time[1]- '0');
			mm = int(time[3] - '0') *10 + int(time[4] - '0');
			now.time = hh * 60 + mm;
			mp[now.sfz] = -1;
			aa.push_back(now) ;
		} 
		sort(aa.begin(),aa.end(),cmp);
		a.push_back(aa);
	}
}
int main(){
	unit();
	run();
	return 0;
} 

