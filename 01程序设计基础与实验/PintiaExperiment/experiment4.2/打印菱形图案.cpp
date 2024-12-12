#include <bits/stdc++.h>
using namespace std;

int uphalf(int n) {
    for(int i = 1;i <= (n-1)/2; i++) { //iterate in the order of rows
        for(int j = ((n+1)/2-i); j > 0; j--) {
            cout<<"  " ;//print blank
        }
        for(int k = 2*i-1;k > 0;k--) {
            cout<<"* ";
        }
        cout<<'\n';
    }
    return 0;
}
int downhalf(int n) {
    for(int i = 1;i <= ((n-1)/2); i++){
        for(int j = 0;j < i;j++) {
            cout<<"  ";
        }
        for(int k = n-2*i;k > 0;k--) {
            cout<<"* ";
        }
        cout<<'\n';
        
    }
    return 0;
}
int mid(int n) {
    for(int i = 0;i < n;i++) {
        cout<<"* ";
    }
    cout<<'\n';
    return 0;
}
int main(){
    int n;
    cin>>n;

    uphalf(n);
    mid(n);
    downhalf(n);

    return 0;
}