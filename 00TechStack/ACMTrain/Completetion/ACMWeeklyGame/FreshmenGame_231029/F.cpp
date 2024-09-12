#include <bits/stdc++.h>
using namespace std;
int a[4];
int mix,pos=0;
int sort(){
	cin>>a[0]>>a[1]>>a[2]>>a[3];
	mix = a[0];
	for(int i = 0;i<4;i++){
		if(a[i] > mix)
		{
			mix = a[i];
			pos = i;
		}
	}
	mix = a[3];
	a[3] = a[pos];
	a[pos] = mix;
	return 0;
}
int guess(){
	for(int i =0;i<3;i++){
		a[i] = a[3] -a[i];
	}
	return 0;
}
int main(void){
	sort();
	guess();
	cout<<a[0]<<' '<<a[1]<<' '<<a[2];
	return 0;
}