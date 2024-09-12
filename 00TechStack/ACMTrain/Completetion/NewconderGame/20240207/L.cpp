#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0),cin.tie(0);

    int T ; cin >> T;
    if(T == 1) {
        cout << 0 << endl;
        return 0;
    }else{
        int cot3  = 0 , cot6 = 0  , cot7 = 0 , cot2 = 0 , cot10 = 0 ,cot8 = 0 ;
        while(T--){
            int tmp ;cin >> tmp;
            switch(tmp){
                case 2 : cot2++ ; break;
                case 3 : cot3++ ; break;
                case 6 : cot6++ ; break;
                case 7 : cot7++ ; break;
                case 10: cot10++ ; break;
                case 8: cot8++;break;
            }
        } 
        int ans = 0 ;
        ans = cot2 * cot7 + cot3 * cot6 + cot10 * cot8;
        cout << ans;
    }
    return 0;
}