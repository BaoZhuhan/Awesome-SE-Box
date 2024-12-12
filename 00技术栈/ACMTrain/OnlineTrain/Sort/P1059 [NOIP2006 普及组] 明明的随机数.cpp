#include <bits/stdc++.h>
using namespace std ;

const int N = 105 ; 

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    
    int n ; cin >> n ; 

    vector<int> a;

    int countNum = 0 ;

    for(int i = 0 ; i < n ; i++) {
        int tmp ; cin >> tmp ;
        if(count(a.begin() ,a.end() , tmp) ==  0 ) {
            a.push_back(tmp);
            countNum += 1; 
        }
    }

    sort(a.begin() , a.end() );

    cout << countNum << endl; 
    for(auto i : a ) cout << i << ' ' ; 

    return 0;

}