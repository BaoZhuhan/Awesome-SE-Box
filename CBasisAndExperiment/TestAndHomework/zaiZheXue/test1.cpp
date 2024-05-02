#include <bits/stdc++.h>
using namespace std;

int f(int n){
    if(n){
        return f(n-1)+n;
    }else{
        return n;
    }
}
int main(){
    cout << f(4);
    return 0;
}