#include <bits/stdc++.h>
using namespace std;
int p = 0;
int  run(int n){
    for(int i = 0;i <= n; i++) {
        
        cout<<(char)('A'+p)<<' ';
        p++;
    }
    cout<<'\n';
    return 0;
}
int main(void){
    int n;
    cin>>n;
    while(n--){
        run(n);
    }
    return 0;
}