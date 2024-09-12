#include <stdio.h>

char* StrInsert(char *dst, int idx, const char *src);

int main()
{
    char a[1024], b[1024];
    int i;
    gets(a);
    scanf("%d%*c", &i);
    gets(b);
    StrInsert(a, i, b);
    puts(a);
    return 0;
}

/* 你提交的代码将被嵌在这里 */

char* StrInsert(char *dst, int idx, const char *src){
    if (idx < 0 ) return dst;
    int dstlen = 0;
    for (int i = 0 ; dst[i] != '\0' ; i++) {
        dstlen++;
    }
    if (idx > dstlen ) return dst;
    int srclen = 0;
    for(int i = 0 ; src[i] != '\0' ; i++) {
        srclen++;
    }

    for(int i = idx ; i < dstlen ; i ++){
        dst[i+srclen] = dst[i];
        dst[i] = src[i-idx];
    }
    dst[dstlen + srclen] = '\0';
    return dst;
}