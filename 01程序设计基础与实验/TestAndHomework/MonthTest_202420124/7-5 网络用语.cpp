#include <bits/stdc++.h>
using namespace std;

int main(){
	int n ;
	cin >> n;
	vector<string> v;
	string res;
	for(int i = 0 ; i < n ; i++ ){
		string s;
		cin >> s;
		v.push_back(s);
	}
	string word;
	cin >> word;
	bool tmp_flag = false;
	for(int i = 0 ;i <= word.size() ; i++){
//		cout << i << endl;
		for(int j = 0 ; j < v.size() ; j++){
			if(word[i] == v[j][0]){
				bool flag = true;
				int k;
				for(k = 0 ; k < v[j].size() ; k++){
					if(word[i+k] != v[j][k]){
						flag = false;
					}
				}
				if(flag == true){
					res += '*';
					res += v[j];
					res += '*';
					i+=k;
//					cout << "weizhi-->" << i << "<--weizhi" << endl;
					i -=1;
					tmp_flag = true;
					break;
				}
			}
		}
		if(tmp_flag == true){
			tmp_flag = false;
			continue;
		}
		res += word[i];
	}
	cout << res;
	return 0;
}