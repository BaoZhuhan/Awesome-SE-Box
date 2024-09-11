#include <bits/stdc++.h>
using namespace std;

void f(int* p1){
    *(p1 + 2) = 2;
    cout << *(p1+2);
}
int main(){
    int a[5] = {1,2,3,4,5};
    int *p = a;
    f(p);
    cout << *(p+2);
    return 0;
}