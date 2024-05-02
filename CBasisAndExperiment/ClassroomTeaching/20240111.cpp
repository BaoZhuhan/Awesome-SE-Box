#include <bits/stdc++.h>
using namespace std;

int main(){
    FILE *fp1 ,*fp2;
    int res;
    if((fp1 = fopen("filetest","a")) == NULL){
        printf("File open error");
        exit(0);
    }if((fp2 = fopen("filewritten","w"))== NULL){
        printf("File open error");
    }
    else{
        while(!feof(fp1)){
            fscanf(fp1,"%d",&res);
            fprintf(fp2,"%d", res);
        }
    }

    fclose(fp1);
    fclose(fp2);
    return 0;
}