int Power(int N, int k){
    N = N % 10007;
    int ans = 1;
    while(k > 0 ) {
        if(k % 2 == 1){
            ans = ans * N % 10007;
        }
        k >>= 1;
        N = N * N % 10007;
    }
    return ans;
}