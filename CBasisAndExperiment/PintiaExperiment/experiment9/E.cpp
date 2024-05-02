#include <bits/stdc++.h>
using namespace std;
int res[4];
float input(int x){
    int tmp1 , tmp2;
    scanf("%d/%d",&tmp1 ,&tmp2);
    res[x] = tmp1;
    res[x+1] = tmp2;
    return (float)tmp1/tmp2;

}
int main(){
    float num1 = input(0);
    float num2 = input(2);
    if(num1 == num2){
        printf("%d/%d = %d/%d",res[0],res[1],res[2],res[3]);
    }else if(num1 > num2){
        printf("%d/%d > %d/%d",res[0],res[1],res[2],res[3]);
    }else{
        printf("%d/%d < %d/%d",res[0],res[1],res[2],res[3]);
    }
    return 0;
}