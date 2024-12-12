#include <bits/stdc++.h>
using namespace std;
double prime(double num);
double pow1(double d,int z);
int run(double x){
    double last=1;
    double e = 1;
    for(int i = 1;last>=0.00001;i++){
        last = pow1(x,i)/prime(i);
        e += last;
    }
    printf("%.4lf",e);
    return 0;
    
}
double prime(double num){
    double sum= 1;
    for(int i =1;i <= num;i++){
        sum *= i;
    }
    return sum;
}
double pow1(double d,int z){
    double sum = 1;
    while(z){
        sum *= d;
        z--;
    }
    return sum;
}
int main(void){
    double x;
    cin>>x;
    run(x);
    return 0;
}