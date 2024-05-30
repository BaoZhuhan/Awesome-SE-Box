#include <bits/stdc++.h>
using namespace std;

struct node{
    string name;
    string xh;
    int score;
};

bool cmp(struct node a, struct node b){
    return a.score > b.score;
}

int main(){
    int n;
    cin >> n;
    vector<struct node> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].name >> v[i].xh >> v[i].score;
    }
    sort(v.begin(), v.end(), cmp);
    cout << v[0].name << " " << v[0].xh << endl;
    cout << v[n-1].name << " " << v[n-1].xh << endl;
    return 0;
}