#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int a[N],b[N],c[N];

signed main(void){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int  n ; cin >> n;
	int min,minn = 0;cin >> min ; a[0] =min;b[minn++] = 0;
	for(int i = 1 ; i < n ; ++i){
		cin >> a[i];
		if(a[i] < min){
			memset(b , 0 , sizeof(b));
			memset(c , 0 , sizeof(c));
			min=a[i];
			minn=0;
			b[++minn] = i;
		}
		else if(a[i] == min){
			b[++minn] = i;
			c[minn] = b[minn]- b[minn-1];
		}
	}
	int len = c[2];
	int i = 1;

	for(i = 3 ; i <= minn ; i++){
		if(c[i] < len) len = c[i];
	}
	cout << len;
	return 0;
}