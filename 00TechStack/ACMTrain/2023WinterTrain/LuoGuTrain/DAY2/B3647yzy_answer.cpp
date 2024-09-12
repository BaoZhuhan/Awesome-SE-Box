#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int main(){
     int n,m;cin>>n>>m;
     vector<vector<int>> graph(n, vector<int>(n, INF));
     for(int i=0;i<n;++i)graph[i][i] = 0;
     for(int i=0;i<m;++i){
         int u,v,w;cin>>u>>v>>w;
         --u;--v;
         graph[u][v]=min(graph[u][v], w);
         graph[v][u]=min(graph[v][u], w);
     }
     for(int k=0;k<n;++k){
         for(int i=0;i<n;++i){
            for(int j=0;j<n;++j) {
              if(graph[i][k]<INF&&graph[k][j]<INF)
                   graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
            }
         }
     }
     for(int i=0;i<n;++i){
         for(int j=0;j<n;++j)
            cout<<graph[i][j] << " ";
         cout << endl;
     }
     return 0;
}