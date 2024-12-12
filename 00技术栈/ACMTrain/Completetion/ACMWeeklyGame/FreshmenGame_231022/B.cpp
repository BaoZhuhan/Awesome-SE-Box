#include <stdio.h>

int main(void){

    //setting
    int a,b,c,n;
    scanf("%d",&n);

    //calculate
    for(int i =0;i<n;i++){
        int flag = 0;
        scanf("%d%d%d",&a,&b,&c);
        if(c==(a+b)) flag =1;
        else if(a == (b+c)) flag =1;
        else if(b==(a+c)) flag =1;
        else printf("NO\n");
        if(flag ==1) printf("YES\n");
    }
    
    return 0;

}