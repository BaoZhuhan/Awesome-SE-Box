#include <stdio.h>

char *StrRemove(char *str, int idx, int len);

int main() {
    char a[1024];
    int i, n;
    gets(a);
    scanf("%d%d", &i, &n);
    StrRemove(a, i, n);
    puts(a);
    return 0;
}

/* 你提交的代码将被嵌在这里 */

char *StrRemove(char *str, int idx, int len) {
    if (idx < 0 || len <= 0)
        return str;
    int strlen = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        strlen++;
    }

    if (idx > strlen - 1)
        return str;
    if (idx + len > strlen - 1)
        len = strlen - idx;

    for (int i = idx; i + len < strlen; i++) {
        str[i] = str[i + len];
    }
    str[strlen - len] = '\0';
    return str;
}