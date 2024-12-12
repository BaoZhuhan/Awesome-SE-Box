#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,i=0,j,c=0;
    cin >> n;
    int k=0,l=n-1;    
    int a[n][n];
    while(k<=l){      
        for( j=k ;j<=l;j++) a[k][j]=++c;
        for(i=k+1;i<=l;i++) a[i][l]=++c;
        for(j=l-1;j>=k;j--) a[l][j]=++c;
        for(i=l-1;i>k ;i--) a[i][k]=++c;
        k++;l--;
    }
    
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
           printf("%3d",a[i][j]);
        printf("\n");
    }
    return 0 ;
}