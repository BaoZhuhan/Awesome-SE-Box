#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    int cot_3 = 0 , cot_7 = 0;
    while(T--){
        int n;
        cin >> n ;
        bool flag = true;
        if(n == 1){
            flag = false;
        }
        for(int i = 2 ; i < sqrt(n) ; i++ ){
            if(n%i == 0){
                flag = false;
            }
        }
        if(flag == true){
            int tmp = n%10;
            if(tmp == 3){
                cot_3++;
            }else if(tmp == 7){
                cot_7++;
            }
        }
    }
    cout << "3:" << cot_3 << endl;
    cout << "7:" << cot_7 << endl;
    return 0;
}