#include <stdio.h>

#define MAXS 10

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

int main()
{
    char str[MAXS], ch_start, ch_end, *p;
    
    scanf("%s\n", str);
    scanf("%c %c", &ch_start, &ch_end);
    p = match(str, ch_start, ch_end);
    printf("%s\n", p);

    return 0;
}

/* 你的代码将被嵌在这里 */