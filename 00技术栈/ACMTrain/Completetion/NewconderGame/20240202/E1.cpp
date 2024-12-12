#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector<pair<int, int>> match(m+1);
    for(int i = 1; i <= m; i++) cin >> match[i].first >> match[i].second;
    int best_rank = n;
    for(int i = 0; i < (1 << m); i++){
        vector<int> score = a;
        for(int j = 0; j < m; j++){
            if(i & (1 << j)){
                score[match[j+1].first] += 3;
            }else{
                score[match[j+1].second] += 3;
            }
        }
        sort(score.begin()+2, score.end(), greater<int>());
        int rank = 1;
        for(int j = 2; j <= n; j++){
            if(score[1] < score[j]) rank++;
            else break;
        }
        best_rank = min(best_rank, rank);
    }
    cout << best_rank << endl;
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