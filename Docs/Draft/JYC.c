#include <stdio.h>

char* StrRemove(char* str, int idx, int len);

int main(){
    char a[1024];
    int i, n;
    gets(a);
    scanf("%d%d", &i, &n);
    StrRemove(a, i, n);
    puts(a);
    return 0;
}

/* 你提交的代码将被嵌在这里 */

char* StrRemove(char* str, int idx, int len){
    int s = 0, i;
    for(;str[s] != '\0';s++);
    if(idx >= s || idx < 0 || len <= 0) return str;
    //if(len>s-idx) len=s-idx;
    for(i = idx;i < idx + len;i++){
        if(i + len >= s) break;
        str[i] = str[i + len];
    }
    str[i] = '\0';
    return str;
}