#include <bits/stdc++.h>
using namespace std;

int n , m ;
int in[(int)5e3+2];
int out[(int)5e3+2];
vector<int> a[(int)5e3+2];
queue<int> q;
int ans ;
int num[(int)5e3+2];

void run(){
    scanf("%d%d",&n,&m);
    for(int i = 1 ;  i <= m ;i++) {
        int x ,y ;
        scanf("%d%d",&x,&y);
        ++in[y],++out[x];
        a[x].push_back(y);
    }

    for(int i = 1 ; i <= n; i++){
        if(!in[i]){
            num[i]= 1;
            q.push(i);
        }
    }
    while(!q.empty()){
        int tot = q.front();
        q.pop();
        int len = a[tot].size();
        for(int i = 1 ; i <= n ; i++ ){
            int next = a[tot][]

        }
    }
}
int main(){
    int T = 1;
    //cin >> T;
    while(T--) {run();}
    return 0;
}