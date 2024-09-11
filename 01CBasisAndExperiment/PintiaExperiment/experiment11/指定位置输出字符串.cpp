
char *match( char *s, char ch1, char ch2 ){
    int flag = 0;
    char *res;
    int i;
    for(i = 0 ; s[i] != '\0' ; i++){
        if(flag == 0 && s[i] == ch1){
            res = &s[i];
            flag = 1;
        }
        if(flag == 1){
            printf("%c", s[i]);
        }
        if(flag == 1 && s[i] == ch2){
            printf("\n");
            return res;
        }
    }
    if(flag == 1){
        printf("\n");
        return res;
    }else{
        res = &s[i];
        printf("\n");
        return res;
    }
}
