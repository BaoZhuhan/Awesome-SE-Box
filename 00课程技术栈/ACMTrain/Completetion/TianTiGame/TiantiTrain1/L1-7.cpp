#include <bits/stdc++.h>
using namespace std ;


int a[3][3];
int xx[3];
int yy[3];
int ans[4];

map<int,int> ss;

void unit(){
ss[6]=10000;
ss[16]=72;
ss[7]=36;
ss[17]=180;
ss[8]=720;
ss[18]=119;
ss[9]=360;
ss[19]=36;
ss[10]=80;
ss[20]=306;
ss[11]=252;
ss[21]=1080;
ss[12]=108;
ss[22]=144;
ss[13]=72;
ss[23]=1800;
ss[14]=54;
ss[24]=3600;
ss[15]=180;
}


void run(){
	int locx = -1, locy = -1;
	for(int i = 0 ; i < 3 ; i++ ) {
		for(int j = 0 ; j < 3 ; j ++) {
			cin >> a[i][j];
			if(a[i][j] == 0) {
				locx = i;
				locy = j;
			}
		}
	}
	
	if(locx != -1){
		int tt[10] = {0};
		for(int i = 0 ; i < 3 ; i++ ) {
			for(int j = 0 ; j < 3 ; j ++) {
				tt[a[i][j]] = 1;	
			}
		}
		for(int i = 0 ; i < 10 ; i++) {
			if(tt[i] == 0){
				a[locx][locy] = i;
			}
		}
	}
	
	
	
	for(int i = 0 ; i < 3 ; i++){
		cin >> xx[i] >> yy[i];
		ans[i] = a[xx[i]-1][yy[i]-1];
	}
	
	int fwd;
	cin >> fwd;
	
	if(fwd <= 3) {
		for(int i = 0 ;i < 3 ;i++){
			ans[3] += a[fwd-1][i]; 
		}
	}else if(fwd <= 6){
		for(int i = 0 ; i < 3 ;i++){
			ans[3] += a[i][fwd-1];
		}
	}else if(fwd  == 7){
		ans[3] += a[0][0];
		ans[3] += a[1][1];
		ans[3] += a[2][2];
	}else if(fwd == 8){
		ans[3] += a[0][2];
		ans[3] += a[1][1];
		ans[3] += a[2][0];
	}
	
	ans[3] = ss[ans[3]];
	
	for(int i = 0 ; i < 4 ;i++) {
		cout << ans[i] << endl;
	} 
	
}
int main(){
	unit();
	run();
	return 0;
} 