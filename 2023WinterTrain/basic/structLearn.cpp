#include <bits/stdc++.h>
using namespace std ;

struct point{
    int x , y ;
    point(int x = 0 , int y = 0 ) : x(x) , y(y) {}
};

point operator+ (const point& A ,const point& B) {
    return point(A.x + B.x , A.y + B.y) ;
}

ostream& operator << (ostream &out , const point& p) {
    out << "(" << p.x << "," << p.y << ")" ;
    return out ;
}

int main() {
    point a , b(1,2) ;
    a.x = 3 ;
    cout << a+b << endl ;
    
    return 0;
}