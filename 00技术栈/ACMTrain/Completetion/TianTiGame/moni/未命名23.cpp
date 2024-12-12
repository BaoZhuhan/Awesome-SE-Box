#include<bits/stdc++.h>
using namespace std;

void run(){
	int a[9][9];
	bool flag = true;
	
	//h
	for(int i = 0 ; i < 9 ;i++) {
		set<int> s;
		for(int j = 0 ; j < 9 ; j++){
			cin >> a[i][j];
			if(s.count(a[i][j]) == 0) s.insert(a[i][j]);
			else {flag = false ; cout << "h " << i << ' ' << j << ' ' << a[i][j]<< endl; }
		}
	}
	
	//s
	if(flag == true){
		for(int i = 0 ; i < 9 ; i++){
			set<int> s;
			for(int j = 0 ; j < 9 ; j++){
				if(s.count(a[j][i] == 0)) s.insert(a[j][i]);
				else {flag = false ; cout << "s " << i << ' ' << j << ' ' << a[j][i]<< endl; }
			}
		}
	}
	
	//1
	if(flag == true){
		set<int> s;
		for(int i = 0 ; i < 3 ; i++){
			for(int j = 0 ; j < 3 ; j++){
				if(s.count(a[i][j]) == 0) s.insert(a[i][j]);
				else {flag = false ; cout << "1 " << i << ' ' << j << ' ' << a[i][j]<< endl; }
			}
		}
	}
	
	//2
	if(flag == true){
		set<int> s;
		for(int i = 3 ; i < 6 ; i++){
			for(int j = 0 ; j < 3 ; j++){
				if(s.count(a[i][j]) == 0) s.insert(a[i][j]);
				else {flag = false ; cout << "2 " << i << ' ' << j << ' ' << a[i][j]<< endl; }
			}
		}
	}
	
	//3
	if(flag == true){
		set<int> s;
		for(int i = 6 ; i < 9 ; i++){
			for(int j = 0 ; j < 3 ; j++){
				if(s.count(a[i][j]) == 0) s.insert(a[i][j]);
				else {flag = false ; cout << "3 " << i << ' ' << j << ' ' << a[i][j]<< endl; }
			}
		}
	}
	
	//4
	if(flag == true){
		set<int> s;
		for(int i = 0 ; i < 3 ; i++){
			for(int j = 3 ; j < 6 ; j++){
				if(s.count(a[i][j]) == 0) s.insert(a[i][j]);
				else {flag = false ; cout << "4 " << i << ' ' << j << ' ' << a[i][j]<< endl; }
			}
		}
	}
	
	//5
	if(flag == true){
		set<int> s;
		for(int i = 3 ; i < 6 ; i++){
			for(int j = 3 ; j < 6 ; j++){
				if(s.count(a[i][j]) == 0) s.insert(a[i][j]);
				else {flag = false ; cout << "5 " << i << ' ' << j << ' ' << a[i][j]<< endl; }
			}
		}
	}
	
	//6
	if(flag == true){
		set<int> s;
		for(int i = 6 ; i < 9 ; i++){
			for(int j = 3 ; j < 6 ; j++){
				if(s.count(a[i][j]) == 0) s.insert(a[i][j]);
				else {flag = false ; cout << "6 " << i << ' ' << j << ' ' << a[i][j]<< endl; }
			}
		}
	}
	
	//7
	if(flag == true){
		set<int> s;
		for(int i = 0 ; i < 3 ; i++){
			for(int j = 6 ; j < 9 ; j++){
				if(s.count(a[i][j]) == 0) s.insert(a[i][j]);
				else {flag = false ; cout << "7 " << i << ' ' << j << ' ' << a[i][j]<< endl; }
			}
		}
	}
	
	//8
	if(flag == true){
		set<int> s;
		for(int i = 3 ; i < 6 ; i++){
			for(int j = 6 ; j < 9 ; j++){
				if(s.count(a[i][j]) == 0) s.insert(a[i][j]);
				else {flag = false ; cout << "8 " << i << ' ' << j << ' ' << a[i][j]<< endl; }
			}
		}
	}
	
	//9
	if(flag == true){
		set<int> s;
		for(int i = 6 ; i < 9 ; i++){
			for(int j = 6 ; j < 9 ; j++){
				if(s.count(a[i][j]) == 0) s.insert(a[i][j]);
				else {flag = false ; cout << "9 " << i << ' ' << j << ' ' << a[i][j]<< endl; }
			}
		}
	}
	
	cout << (flag ? 1 : 0) << endl; 
}

int main(){
	int T;
	cin >> T;
	while(T--)run();
	return 0;
} 
