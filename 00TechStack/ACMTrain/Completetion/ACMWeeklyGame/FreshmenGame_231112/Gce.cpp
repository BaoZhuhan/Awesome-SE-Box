#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
signed main(void){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string a;cin >> a;
	int res=0 ,flag =0,p1,p2;
	int len = 0 , count = 1 ,maxt=0,maxn=0;
    int templen;
	for(int i = 0 ; i < a.size() ; ++i){		
		if(flag==0 && a[i] == '('){
			p1 = i;
			res++;
			flag = 1;
			templen = 1;
		}
		else if(flag && a[i] == '(') {
			res++;	
			if(templen>1){
				if(maxt<templen){
					maxn = 1;
					maxt = templen;
				}
				else if(maxt==templen){
					maxn++;
				}
				templen = 0;
			}
			
		}
		else if(flag && a[i] == ')') {
			res--;
			templen++;
		}
		if(res <= 0 && flag ) {
			flag = 0;
			p2 = i;
			if((p2-p1) > len){
				len = p2-p1;
				count = 1;				
			}
			else if((p2-p1)== len) {
				count++;			
			}
			res =0;p1=0;p2=0;
		}	
	}
	if(maxt >= len) cout << maxt<<' ' << maxn;
	else if(len != 0 || templen > 1) cout << len+1 <<' ' << count;
	else cout <<"0 1";
	return 0;
}