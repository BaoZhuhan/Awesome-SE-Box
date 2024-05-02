#include <bits/stdc++.h>
using namespace std;
int y[10000];
int flag =0;
int find(int a){
    memset(y, 0, sizeof(y));
    int sum = 0,j = 0;
    for(int i = 1;i < a;i++){
        if(a%i == 0){
            sum += i;
            y[j] = i;
            j++;
        }
    }
    if(sum == a){
        flag = 1;
        cout<<a<<" =";
        int k = 0;
        for(k = 0;y[k+1] != 0;k++){
            cout<<' '<<y[k]<<" +";
        }
        cout<<' '<<y[k]<<'\n';
    }
    return -1;

}
int main(void){
    int n,m;
    cin>>n>>m;
    for(int i = n;i <= m;i++){
        find(i);
    }
    if(!flag) cout<<"None";
    return 0;
}