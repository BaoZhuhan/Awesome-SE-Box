#include<bits/stdc++.h>
using namespace std;


void run(){
	int n ;cin >> n ;
	vector<float> s(n+1 , 0);
	vector<int> c(n+1 , 0);
	for(int i = 1 ; i <= n ;i ++){
		cin >> s[i];
	}
	
	float sum = 0;
	
	int a , b ;
	cin >> a >> b;
	while(a != 0){
		c[a]++;
		sum += s[a]*b;
	}
	
	for(int i = 1 ; i < n ; i++){
		cout << i << " " << c[i] << endl;
	}
	
	cout << sum;
}

int main(){
	run();
	return 0;
} 
