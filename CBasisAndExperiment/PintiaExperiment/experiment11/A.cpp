int getindex( char *s ){
    int flag = 0;
    char a[7][20] = {
        "Sunday",
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday",
        "Friday",
        "Saturday"
    };

    for(int i = 0 ; i < 7 ;i++){
        if(strcmp(a[i] , s ) == 0){
            return i;
        }
    }
    return -1;
}