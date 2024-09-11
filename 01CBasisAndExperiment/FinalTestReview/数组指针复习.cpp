#include <bits/stdc++.h>
using namespace std;

void f( int (*p)[2] ){
    cout << p[1][1];
}
int main(){
    int a[3][2] = {{1,2},{3,4},{5,6}};
    f(a);
}