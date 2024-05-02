#include <stdio.h>
#define MAXS 30

char *search(char *s, char *t);

int main()
{
    char s[] = "The C Programming Language";
    char t[] = "ram";
    
    char *pos = NULL ;
    pos = search(s, t);
    if ( pos != NULL )
        printf("%d\n", pos - s);
    else
        printf("-1\n");

    return 0;
}

/* 你的代码将被嵌在这里 */
char *search(char *s, char *t){
    int flag = 0;
    char *p1 = s;
    char *p2 = t;
    for(; *(s) != '\0' ; s++){
        if(*(s) == *(px2)){
            flag = 1;
            char *p1 = s;
            while(*(p2) != '\0'){
                if(*(p1) == '\0' || *(p1) != *(p2)){
                    flag = 0;
                    p2 = t;
                    break;
                }else{
                    p1++;
                    p2++;
                }
            }
            if(flag == 1){
                return s;
            }
        }
    }
    return NULL;
} 