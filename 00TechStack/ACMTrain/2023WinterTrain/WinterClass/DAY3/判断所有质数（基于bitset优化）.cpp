#include <bits/stdc++.h>
using namespace std;

vector<int> prime;

void get_prime(int n){
    //复杂度 nloglogn  名称：埃式筛
    //判断所有质数
    bitset<10000000> vis;//对他bitset优化
    for(int i = 2 ; i <= n ; i++){
        if(vis[i]) continue;
        prime.push_back(i);
        for(int j = i *2 ; j <= n ;j += i ) vis[j] = true;
    }
}

void solve(){
    bitset<10000> a,b;//当成一个bool数组
    a = b;//按位操作
    a.reset(0);//重置为0
    // 所有的bitset操作的复杂度都是 n/w , 期中w是机器的字长 ，32位/64位
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}