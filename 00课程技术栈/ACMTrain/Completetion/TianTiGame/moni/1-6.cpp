#include <bits/stdc++.h>
using namespace std;


void run(){
	string s;
	getline(cin,s);
	int n;
	cin >> n;
	for(int i = 0 ; i < n ; i ++){
		int a , b ;
		cin >> a >> b;
		string s1 ,s2;
		cin >> s1 >> s2;
		
		string s3; // qian
		string s4; // cut
		string s5; // hou
		for(int j = 0 ; j < s.size() ; j++){
			if(j < a){
				s3 += s[j];
			}else if(j <= b){
				s4 += s[j]; 
			}else{
				s5 += s[j];
			}
			
		}
		
		s = s3 + s5;
		
		s3 = "";
		s5 = "";
		
		for(int j = 0 ; j < s.size() ; j++){
			bool flag = false;
			if(flag == true){
				s5 += s[j];
			}
			if(flag == false and s[j] != s1[0]){
				s3 += s[j];
			}
			else if(flag == false and s[j] == s1[0]){
				bool tf = true;
				int k , l ;
				for(k = 0 ; k < s1.size() ; k++){
					if(s[j+k] != s1[k]){
						tf = false;
						break;						
					}
				}
				if(tf){
					for(l = 0 ; l < s2.size() ; l++){
						if(s[j+k+s4.size()] != s2[l]){
							tf = false;
							break;
						}
					}
					if(tf){
						flag = true;
						s5 = s3 + s1 + s4 + s2;
						j = j + k + l;
					}
				}
			}
		}
		
		s = s5;
		
	}
	
	cout << s;
}
int main(){
	run();
	return 0;
}
