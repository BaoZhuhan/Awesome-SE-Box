#include <bits/stdc++.h>
using namespace std;

int main(void){
	char a[256] = {0};
	cin>>a;
    int c = strlen(a);
    for(int i = 0;i<c;i++){
        
        cout<<(char)a[i]<<' ';

    }
    return 0;
}