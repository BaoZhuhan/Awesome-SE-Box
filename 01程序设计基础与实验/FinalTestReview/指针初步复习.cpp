#include <bits/stdc++.h>
using namespace std;

void f(int* &p1 , int* &q1){
    int *tmp;
    tmp = p1;
    p1 = q1;
    q1 = tmp;
    cout << *p1 << endl;
    cout << p1 << endl;
}
int main(){
    int a = 1;
    int b = 2;
    int *p = &a;
    int *q = &b;
    int *tmp;
    tmp = p;
    p = q;
    q = tmp;
    f(p,q);
    cout << *p << *q;
    return 0;
}