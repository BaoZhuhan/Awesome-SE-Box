#include <stdio.h>


int main(void){
    int n =0,yx=0,hg=0,my=0;
    scanf("%d",&n);
    int a[n];
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        if(a[i]>=85) yx+=1;
        else if(a[i]>=60) hg+=1;
        else my++;
    }
    printf("%d %d %d",yx,hg,my);
    return 0;
}