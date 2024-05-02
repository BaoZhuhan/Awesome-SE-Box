#include <bits/stdc++.h>
using namespace std;

int main(void){
    int t ;
    scanf("%d", &t);
    int res = t;
    char c;
    scanf("%c" , &c);
    
    while(c != '='){

        scanf("%d" ,&t);
        if(c == '/') {
            if(t == 0){
                cout << "ERROR" << endl;
                return 0;
            }
            res /= t;
        }

        else if(c == '+') res += t;
        else if(c == '-') res -= t;
        else if(c == '*') res *= t;

        else {
            cout << "ERROR" << endl;
            return 0;
        }
        scanf("%c" , &c);
    }

    cout << res << endl;
    return 0;
}