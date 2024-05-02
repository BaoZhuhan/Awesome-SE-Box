#include <bits/stdc++.h>
using namespace std;
int prime( int p ){
    if(p==1 || p<=0 ) return 0;
    int flag =1;
    for(int i=2;i<p;i++){
        if(p%i ==0) flag = 0;
    }
    return flag;
}
int main(void){
    int n;
    cin>>n;
    long max = pow(2.0,(float)n)-1;
    double x= 1;
    if(n<2) {
        cout<<"None";
        return 0;
    }
    for(int i = 1;x<max;i++){
        x= pow(2.0,(float)i)-1;
        if(prime((long) x)) cout<<x<<'\n';
    }
    return 0;
}