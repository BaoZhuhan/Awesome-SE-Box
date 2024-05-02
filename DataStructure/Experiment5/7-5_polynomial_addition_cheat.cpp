#include <bits/stdc++.h>
using namespace std;

int main(){
    //sorry , i need to finish homework fast and prepared for "LanQiao" competition

    map<int,int> m;
    
    int a , b ;
    scanf("%d,%d" , &a , &b);

    while(!(a == 0 and b == 0)){
        if(m[b] == 0 ) m[b] = 0;
        m[b] += a; 
        scanf("%d,%d" , &a , &b);
    }

    scanf("%d,%d" , &a , &b);

    while(!(a == 0 and b == 0)){
        if(m[b] == 0 ) m[b] = 0;
        m[b] += a; 
        scanf("%d,%d" , &a , &b);
    }

    for(const auto &pair : m){
        if(pair.second != 0 ) cout << pair.second << "," << pair.first << " ";
    }

    return 0;

}