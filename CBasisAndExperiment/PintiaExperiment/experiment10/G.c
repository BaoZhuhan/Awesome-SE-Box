unsigned int reverse( unsigned int number ){
    static int x = 0;
    if(number % 10 != 0 || x != 0 ){
        printf("%d",number%10);
        x++;
    }
    number/= 10;
    if(number <= 9 ){
        return number;
    }
    reverse(number);
}