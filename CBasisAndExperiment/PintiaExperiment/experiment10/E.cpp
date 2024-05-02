double fn(double x , int n){
    if(n == 1){
        return x;
    }else{
        if(n % 2 == 0){
            return pow(x,n)*(-1) + fn(x,n-1);
        }else{
            return pow(x,n)*(1) + fn(x,n-1);
        }
    }
}