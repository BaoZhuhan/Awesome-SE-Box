#include <bits/stdc++.h>
using namespace std ;

int strtonum(string s , int p1 , int p2){
	int res = 0;
	for(int i= p1 ; i <= p2 ; i++){
		res*= 10;
		res += (int)(s[i] - '0');
	}
	return res;
}
void run(){
	string s;
	cin >> s;
	int yy = 0 ;
	int mm = 0;
	if(s.size() == 4){
		yy = strtonum(s , 0 , 1);
		mm = strtonum(s , 2 , 3);
		if(yy < 22) yy += 2000;
		else yy += 1900;
	}else if(s.size() == 6){
		yy = strtonum(s, 0 ,3);
		mm = strtonum(s, 4 ,5);
	}else if(s.size() == 7){
		yy = strtonum(s, 0 , 3);
		mm = strtonum(s , 5, 6);
	}
	
	if(mm < 10 ) cout << yy << "-0" << mm;
	else cout << yy << '-' << mm; 
}
int main(){
	run();
	return 0;
}