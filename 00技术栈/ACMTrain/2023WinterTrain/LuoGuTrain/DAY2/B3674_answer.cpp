#include<bits/stdc++.h>
using namespace std;
int long long n,m,u,v,w,a[1001][1001];
              /*n和m表示点的个数和边的条数,u为起点,v为终点,w为距离 
                a为模拟无向图的二维数组*/
int main(){
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){          
            a[i][j]=0x3f3f;
            if(i==j)a[i][j]=0;
            //初始化a 
        }
    }
    for(int i=1;i<=m;i++){
        scanf("%lld%lld%lld",&u,&v,&w);
        a[u][v]=w;
        a[v][u]=w;
        //读入每条路径起点和长度 
    }
    for(int k=1;k<=n;k++){
        //k为中转点 
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
                //比较是中转后的距离短还是直接去短 
                a[j][i]=a[i][j];
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%lld ",a[i][j]);
            //输出表 
        }
        printf("\n");
    }
}