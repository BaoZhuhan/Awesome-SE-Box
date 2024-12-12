#include <stdio.h>

int narcissistic( int number );
void PrintN( int m, int n );
    
int main()
{
    int m,a=1,b;
    scanf("%d",&m);
    for(int i=1;i<m;i++) a*=10;
    b=a*10-1;
    PrintN(a,b);
    return 0;
}

int narcissistic( int number ){
    int sum=0,flag=0,n=0;
    
    for(int num = number;num>0;num/=10){
        n++;
    }

    for(int num = number;num>0;num/=10){
        int a = num%10,b=1;
        for(int i = 0;i<n;i++){
            b*=a;
        }
        sum+=b;
    }
    if(sum==number) flag =1;
    return flag;
}
void PrintN( int m, int n ){
    for(int i =m+1;i<n;i++){
        if(narcissistic(i)) printf("%d\n",i);
    }
}