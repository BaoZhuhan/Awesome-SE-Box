#include <stdio.h>

char* StrMid(char *dst, const char *src, int idx, int len);

int main()
{
    char a[128], b[128];
    int s, n;
    gets(a);
    scanf("%d%d", &s, &n);
    StrMid(b, a, s, n);
    puts(b);
    return 0;
}

char* StrMid(char *dst, const char *src, int idx, int len){
    int j = 0;
    for (int i = 0 ; i <= (idx + len) && src[i] != '\0' && idx >= 0; i++){
        if (i >= idx && i < (idx + len) ){
            dst[j++] = src[i];
        }
    }
    dst[j] = '\0';
    return dst;
}