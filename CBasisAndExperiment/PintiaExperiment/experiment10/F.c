void printdigits(int n){
    static int flag = 0;
    if(n <= 0 && flag == 0){
        printf("0");
    }
    else if(n == 0){
        printf("\0");
    }else{
        flag++;
        printdigits(n/10);
        printf("%d\n" , n%10);
    }
}