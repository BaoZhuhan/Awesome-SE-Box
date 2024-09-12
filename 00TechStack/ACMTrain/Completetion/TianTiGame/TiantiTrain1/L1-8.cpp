#include <bits/stdc++.h>
using namespace std ;

int js(int s1 ,int s2 , char op){
	if(op == '+'){
		return s1 + s2;
	}
	if(op == '-'){
		return s2 - s1;
	}
	if(op == '*'){
		return s2 * s1;
	}
	if(op == '/'){
		return s2 / s1;
	}
}

void run(){
	int  n ;
	cin >>n ;
	stack<int> a;
	for(int i = 0 ; i < n ; i++){
		int tmp;
		cin >> tmp;
		a.push(tmp);
	}
	stack<char> b;
	for(int i = 0 ; i < n-1 ; i++){
		char tmp;
		cin >> tmp;
		b.push(tmp);
	}
	
	int ans = 0;
	bool flag = true;
	int err = 0;
	while((!b.empty()) and flag == true){
		int s1,s2;
		s1 = a.top();
		a.pop();
		s2 = a.top();
		a.pop();
		char op;
		op = b.top();
		b.pop();
		
		int ans = 0 ;
		if(op == '/' and s1 == 0){ 
			flag = false;
			err = s2;
		}
		else{
			ans = js(s1,s2 ,op);
		}
		a.push(ans);
	}
	
	if(flag == false){
		cout << "ERROR: " <<err << "/0";
	}else{
		cout << a.top();
	}
	
}
int main(){
	run();
	return 0;
} 

