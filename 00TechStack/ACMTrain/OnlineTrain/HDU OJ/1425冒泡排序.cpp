#include<bits/stdc++.h>
using namespace std ;

int a[1000001];
#define swap(a,b) {int temp = a ; a = b; b = temp ; } 
int n , m ; 

void bubble_sort(){
    for(int i =  1; i <= n -1 ; i++){
        for(int j  = 1 ; j <= n-i; j++ ){
            if(a[j] > a[j+1]) { swap(a[j] , a[j+1]);}
        }
    }
}
int main(){
    while(~scanf("%d%d",&n,&m)){
        for(int i = 1 ; i <= n ; i++){scanf("%d",&a[i]);}
        bubble_sort();
        for(int i = n ; i >= n - m  +1 ; i --) {
            if(i == n-m+1) printf("%d\n",a[i]);
            else printf("%d ",a[i]);
        }
    }
    return 0;
}
