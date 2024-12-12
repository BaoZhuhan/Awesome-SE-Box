#include <bits/stdc++.h>
using namespace std;

double prob(double p) {
    return pow(1-p, 2) * pow(p, 2) ; 
}
void run(){
    double p ;
    cin >> p;
    cout << prob(p);
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) {run();}
    return 0;
}



