//扩展欧几里得算法 ：
//ax + by == gcd(a,b) ; bx' + (a%b)y' == gcd(b,a%b);
//由gcd(a,b) == gcd(b,a%b)
//联立ax + by  == bx' + (a%b)y'
//ax + by = bx' + (a - a/b*b)y'  这里的除法就是C语言除法，整除
//ax + by = ay' + b*(x' - a/b*y')
//--> x = y' ; y = x' - a/b*y'
//边界条件 ， 如果x = 1 , y = 0 时结束

#include <bits/stdc++.h>
using namespace std;

int exgcd(int a , int b , int &x , int y ){
    //求 $ax + by = \gcd(a,b)$的一组可行解
    //函数返回值为 gcd(a,b)
    if(!b){
        x = 1 , y = 0 ;
        return a;
    }
    int d = exgcd(b,a%b,x,y);
    y -= a / b * x ;
    return d;
}


void solve(){
    
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
