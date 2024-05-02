#include <stdio.h>
#include <string.h>

#define MAXS 80

int getindex( char *s ){
    int flag = 0;
    char a[7][20] = {
        "Sunday",
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday",
        "Friday",
        "Satursday"
    };

    for(int i = 0 ; i < 7 ;i++){
        if(strcmp(a[i] , s ) == 0){
            return i;
        }
    }
    return -1;
}

int main()
{
    int n;
    char s[MAXS];
    
    scanf("%s", s);
    n = getindex(s);
    if ( n==-1 ) printf("wrong input!\n");
    else printf("%d\n", n);

    return 0;
}

/* 你的代码将被嵌在这里 */