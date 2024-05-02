#include<bits/stdc++.h>
using namespace std;
#define maxn 400005
int n,ans,p[maxn];


void solve()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        p[i]=i;
    }
    for(int i=2;i<=n;++i)
    {
        if(p[i]==i)
        {
            for(int j=i;j<=n;j+=i)
            {
                p[j]=p[j]*(i-1)/i;
            }
        }
    }
    for(int i=1;i<n;++i)
    {
        ans+=p[i];
    }
    cout << ( (n==1)? 0 : ans<<1|1 ) ;

}

int main(){
    int T = 1;
    while(T--){
        solve();
    }
    return 0;
}