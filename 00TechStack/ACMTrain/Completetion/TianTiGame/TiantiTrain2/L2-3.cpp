#include <bits/stdc++.h>
using namespace std ;

struct node{
	vector<int> data;
	int cot = 1;
};

int n , m;

bool cmp(node a , node b){
	if(a.cot != b.cot){
		return a.cot > b.cot;
	}else{
		for(int i = 0 ; i < m ; i++){
			if(a.data[i] != b.data[i]){
				return a.data[i] < b.data[i];
			}
		}
	}
	return true;
}

void run(){
	cin >> n >> m;
	vector<node> a(0);
	
	for(int i = 0 ; i < n ; i++){
		node tmp;
		for(int i = 0 ; i < m ; i++){
			int ttmp;
			cin >> ttmp;
			tmp.data.push_back(ttmp);
		}
		
		bool tflag = false;
		for(int i = 0 ; i < a.size() ; i++){
			if(a[i].data == tmp.data){
				a[i].cot++;
				tflag = true;
				break;
			}
		}
		
		if(tflag == false) {
			a.push_back(tmp);
		}
	}
	
	sort(a.begin() , a.end() , cmp);
	
	cout << a.size() << endl;
	for(int i = 0 ; i < a.size() ; i++){
		cout << a[i].cot << " " ;
		for(int j = 0 ; j < m - 1; j++){
			cout << a[i].data[j] <<" ";
		}cout << a[i].data[m-1] << endl;
	}
	
}
int main(){
	run();
	return 0;
}