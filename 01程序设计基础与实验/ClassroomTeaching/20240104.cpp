#include <bits/stdc++.h>
using namespace std;

void fsort(const char *color )
int main(){
    int a[3][3] = { {1,2,3} , {4,5,6} , {7,8,9} };
    int *p;
    p = &a[0][0];
    p = a[0];

    int i = 0 ;
    while(i < 9){
        cout << *p << ' ';
        p++;
        i++;
    }

    return 0;
}