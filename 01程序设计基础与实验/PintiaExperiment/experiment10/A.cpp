int sum(int n){
    if(n <= 0){
        return 0;
    }else if(n == 1){
        return n;
    }else{
        return sum(n-1) + n;
    }
}