#include <bits/stdc++.h>
using namespace std;

int days_nor[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
int days_leap[12] = {31,29,31,30,31,30,31,31,30,31,30,31}; 

int isleap(int y){
    if(y % 400 == 0) return 1;
    if(y % 100 == 0) return 0;
    if(y % 4 == 0) return 1;
    return 0;
}
int main(){
    int y , m , d;
    scanf("%d/%d/%d" , &y ,&m ,&d);
    int sum = 0;
    if(isleap(y)){
        for(int i = 0 ; i < m-1 ; i++ ){
            sum += days_leap[i];
        }
        cout << sum+d;
    }
    else{
        for(int i = 0 ; i < m-1 ;i++ ){
            sum += days_nor[i];
        }
        cout << sum +d;
    }
    return 0;
}