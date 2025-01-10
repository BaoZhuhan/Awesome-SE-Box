#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;cin >> n;
    vector<int> dp;
    for(int i = 1; i <= n; i++) {
        int num ; cin >> num;
        auto it = lower_bound(begin(dp),end(dp),num);
        if(it == dp.end()) dp.push_back(num);
        else *it = num;
    }
    cout << dp.size();
    return 0;
}