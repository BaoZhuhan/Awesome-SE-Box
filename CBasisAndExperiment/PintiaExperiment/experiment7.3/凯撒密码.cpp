#include <bits/stdc++.h>
using namespace std;

int main(void){
    char str[100];
    int i = 0; 
    while((str[i] = getchar())!= '\n'){
        i++;
    }
    str[i] = '\0';
    int offset;
    scanf("%d" , &offset);
    for(int i = 0 ; str[i] != '\0' ; i++){
        if(str[i] >= 'A' and str[i] <= 'Z'){
            str[i] = (char)((int)(str[i] + offset - 'A' + 260000000)%26 + 'A');
        }if(str[i] >= 'a' and str[i] <= 'z'){
            str[i] = (char)((int)(str[i] + offset - 'a' + 260000000)%26 + 'a');
        }
        printf("%c" , str[i]);
    }
    return 0;
}