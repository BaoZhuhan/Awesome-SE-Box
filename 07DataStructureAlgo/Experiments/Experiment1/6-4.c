#include <stdio.h>

// 替换子串
char* StrStuff(char *dst, int idx, int len, const char *src);

int main()
{
    char a[1024], b[1024];
    int i, n;
    gets(a);
    scanf("%d%d%*c", &i, &n);
    gets(b);
    StrStuff(a, i, n, b);
    puts(a);
    return 0;
}

/* 你提交的代码将被嵌在这里 */
char* StrInsert(char *dst, int idx, const char *src) {
    if (idx < 0) return dst;

    int dstlen = 0;
    for (int i = 0; dst[i] != '\0'; i++) {
        dstlen++;
    }
    if (idx > dstlen) return dst;

    int srclen = 0;
    for (int i = 0; src[i] != '\0'; i++) {
        srclen++;
    }

    for (int i = dstlen; i >= idx; i--) {
        dst[i + srclen] = dst[i];
    }

    for (int i = 0; i < srclen; i++) {
        dst[idx + i] = src[i];
    }

    return dst;
}

char* StrRemove(char *str, int idx, int len){
    if(idx < 0 || len <= 0 ) return str;
    int strlen = 0;
    for(int i = 0 ; str[i] != '\0' ; i++){
        strlen++;
    } 

    if(idx > strlen-1 ) return str;
    if(idx + len > strlen-1 ) len = strlen-idx;

    for(int i = idx; i + len < strlen; i++){
        str[i] = str[i + len];
    }
    str[strlen - len] = '\0';
    return str;
}

// 替换子串
char* StrStuff(char *dst, int idx, int len, const char *src){
    StrRemove(dst, idx , len);
    StrInsert(dst, idx,src);
    return dst;
}