#include <bits/stdc++.h>
using namespace std;

int main(){
    int a;
    int b = 1;
    a = (b = 1);
    cout << a << endl;//1
    a = (b = 1 + 2);
    cout << a << endl;//3
    bool f1 = true;
    int c = (f1 == false);
    cout << c << endl;//0
    int d = (f1 == true);
    cout << d << endl;//1
    int e = 1;
    int f = ++e;
    int g = e++;
    int i;
    int h = ( i = e++);
    cout << f << g << h << e << endl;
    int m , n = 5;
    m = n , --n;
    cout << m;
}