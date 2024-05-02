#include<bits/stdc++.h>
using namespace std;
const int MAXI=4e5+4;
int pre[MAXI],head[MAXI],h[MAXI],ans[MAXI],En=0;
bool e[MAXI];
int root(int x)
{
    return pre[x] == x ? x : root(pre[x]);
}
struct edge
{
    int u , v;
    int next;
}a[MAXI];
void insert(int u,int v)
{                           
    a[En].u=u;
    a[En].next=head[u];    
    a[En].v=v;
    head[u]=En;
    En++;
}
int main()
{
    int n,m,k,x,y,total,i,u;
    cin>>n>>m;
    for(i=0;i<n;++i) 
    {
        pre[i]=i;
        head[i]=-1;
    }
    for(i=0;i<m;++i)
    {
        cin>>x>>y;
        insert(x,y);insert(y,x);
    }
    cin>>k;
    total=n-k;
    for(i=1;i<=k;i++)
    {
        cin>>x;
        e[x]=true;    
        h[i]=x;
    }
    for(i=0;i<2*m;i++)
    {
        if(e[a[i].u]==false&&e[a[i].v]==false) 
        {
            if(root(a[i].u)!=root(a[i].v))   
            {
                total--;          
                pre[root(a[i].u)]=pre[root(a[i].v)];
            }
        }
    }
    ans[k+1]=total;
    for(int t=k;t>=1;t--)
    {
        u=h[t]; 
        total++;  
        e[u]=false;  
        for(i=head[u];i!=-1;i=a[i].next) 
        {
            if(e[a[i].v]==false&&pre[root(u)]!=pre[root(a[i].v)])
            {
                total--; 
                pre[root(a[i].v)]=pre[root(u)];
            }
        }
        ans[t]=total;
    }
    for(i=1;i<=k+1;++i) cout<<ans[i]<<endl;
    return 0;
}