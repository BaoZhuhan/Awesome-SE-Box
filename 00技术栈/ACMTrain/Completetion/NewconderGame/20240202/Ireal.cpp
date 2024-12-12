#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int  n ; cin >> n;
    int cot1 = 0 , cot2 = 0;
    int acy = n/8;
    for(int i = 0 ; i < n ; i++){
        int x , y , r ;
        cin >> x >> y >> r ;
        if(fabs(x) < 70 and fabs(y) < 70){
            cot1++;
        }else {
            cot2++;
        }
    }
    cout << (cot1 - acy > cot2 ? "buaa-noob" : "bit-noob") ; 
    return 0;
}