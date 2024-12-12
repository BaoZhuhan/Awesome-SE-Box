char *getmonth( int n ){
    char *month[13]={
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
    };
    if( n > 0 && n < 13){
        return *(month + n -1);
    }else{
        return NULL;
    }
}