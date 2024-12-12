#include <bits/stdc++.h>
using namespace std;

void mysort(char (*p)[11] , int len ){
    char tmp[11] = {'\0'};
    for(int i = 0 ; i < len; i++){
        for(int j = 0; j < len - 1 ; j++){
            if(strlen(p[j]) > strlen(p[j+1])){
                strcpy(tmp , p[j]);
                strcpy(p[j] , p[j+1]);
                strcpy(p[j+1] , tmp);
            }
        }
    }
}

int main(){
    char a[21][11] = {'\0'};
    
    int i = 0 ;
    while(true){
        scanf("%s", &a[i]);
        if(a[i][0] == '#'){
            break;
        }
        i++;
    }

    a[i][0] = '\0';
    int len = i ;
    
    mysort(a,len);
    
    for(int i = 0 ; i < len ; i++){
        printf("%s ", a[i]);
    }
}