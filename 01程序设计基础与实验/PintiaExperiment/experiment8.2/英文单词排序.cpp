#include <bits/stdc++.h>
using namespace std;
int M;
char a[25][11];

void mysort(char (*p)[11] ){
    char tmp[11] = {0};
    for(int i = 0 ; i < M-1 ; i++){
        for(int j = i+1 ; j < M ; j++){
            if(strcmp(p[i] ,p[j]) > 0){
                strcpy(tmp , p[i]);
                strcpy(p[i] ,p[j]);
                strcpy(p[j] , tmp);
            }
        }
    }
}

int main(){
    bool flag = true;
    for(int i = 0 ;i < 25 and flag == true ; i++){
        scanf("%s" , &a[i]);
        if(a[i] == "#"){
            flag = false;
            M = i;
        }
    }
    
    mysort(a);

    for(int i = 0 ; i < M ;i++){
        printf("%s\n",a[i]);
    }
}