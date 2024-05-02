#include <bits/stdc++.h>
using namespace std;

void mysort(char (*p)[100]){
    int i , j;
    char temp[100] = {0};
    for(i = 0 ; i < 4 ; i++){
        for(j = i + 1 ; j < 5 ; j++ ){
            if(strcmp(p[i],p[j]) > 0){
                strcpy(temp , p[i]);
                strcpy(p[i] , p[j]);
                strcpy(p[j] , temp);
            }
        }
    }
}
int main(){
    char a[6][100];
    for(int i = 0 ; i < 5 ;i++){
        int j = 0 ;
        while((a[i][j] = getchar()) != ' ' and a[i][j] != '\n'){
            j++;
        }
        a[i][j] = '\0';
    }

    mysort(a);
    cout << "After sorted:\n";

    for(int i = 0 ; i < 5 ; i++) {
        int j = 0;
        while(a[i][j]!= '\0'){
            cout << a[i][j];
            j++;
        }
        cout << '\n';
    }
    return 0;
}
