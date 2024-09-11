#include <bits/stdc++.h>
using namespace std;
//#define int long long
struct node{
	int hh;
	int mm;
};

vector<int> zhu;
vector<int> pei;
vector<int> tang;

int timediff(node t1,node t2){
	int res;
	res += (t2.hh - t1.hh )*60;
	res += (t2.mm - t1.mm);
	return res;
}

void chief(int td){
	int n ;
	cin >> n;
	int sum = 0;
	bool fz = false;
	bool fp = false;
	bool ft = false;
	for(int i = 0 ; i < n ; i++){
		string tmp;
		cin >> tmp;
		int p = 0;
//		cout << "tmp-->" << tmp  << endl;

		for(int j = tmp.size() - 1 ; j > 0 ; j--){
			p *= 10;
			p += (int)(tmp[j] - '0');
		}
		p--;
		if(tmp[0] == 'Z'){
			sum += zhu[p];
			fz = true;
		}else if(tmp[0] == 'P'){
			sum += pei[p];
			fp = true;
		}else if(tmp[0] == 'T'){
			sum += tang[p];
			ft = true;
		}	
	}
	bool flag = (fz and fp and ft);
	if(flag and sum <= td){
		cout << "Yes\n";
	}else{
		cout << "No\n";
	}
}

int main(){
	int n1 , n2,n3;
	cin >> n1 >> n2 >>n3;
	int tmp;
	for(int i  = 0 ; i < n1 ; i++){
		cin >> tmp;
		zhu.push_back(tmp);
	}for(int i = 0 ; i < n2 ; i++){
		cin >> tmp;
		pei.push_back(tmp);
	}for(int i = 0 ; i < n3 ; i++){
		cin >> tmp;
		tang.push_back(tmp);
	}
	
	node t1 , t2;
	scanf("%d:%d %d:%d",&t1.hh,&t1.mm,&t2.hh,&t2.mm);
	int k;
	cin >> k;
	int td = timediff(t1,t2);
	for(int i = 0 ; i < k ; i++){
		chief(td);
	}
	return 0;
}