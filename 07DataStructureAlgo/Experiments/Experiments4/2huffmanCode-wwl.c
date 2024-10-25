#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int weight;
    int parent;
    int lchild;
    int rchild;
    int visit;
}Huff;

int findmin(Huff haaa[], int size){
    int min;
    for(int i =- 0 ; i < size; i++) {
        if(haaa[i].visit == 0) {
            min = i;
            break;
        }
    }
    for(int i = 0;i < size;i++){
        if(haaa[i].visit == 0 && haaa[min].weight > haaa[i].weight){
            min = i;
        }
    }
    return min;
}

char** huffmanCode(int w[], int N){
    int n = N;
    Huff haaa[2 * n + 1];

    for(int i = 0;i < 2 * n - 1;i++){
        haaa[i].weight = 0;
        haaa[i].parent = 0;
        haaa[i].rchild = 0;
        haaa[i].lchild = 0;
        haaa[i].visit = 0;
    }

    for(int i = 0;i < n;i++){
        haaa[i].weight = w[i];
    }


    int size = n;

    for(int i = 0; i < n - 1; i++){
        int min1 = 0;
        min1 = findmin(haaa, size);
        haaa[min1].visit = 1;

        int min2 = 0;
        min2 = findmin(haaa, size);
        haaa[min2].visit = 1;

        haaa[size].weight = haaa[min1].weight + haaa[min2].weight;
        haaa[min1].parent = size;
        haaa[min2].parent = size;
        haaa[size].lchild = min1;
        haaa[size].rchild = min2;
        size++;
    }


    char **ans = (char**)malloc(N * sizeof(char*));
    char temp[1000];
    for(int i = 0;i < n;i++){
        int now = i;
        int par = haaa[now].parent;
        int len = 0;
        while(par != 0){
            if(haaa[par].lchild == now){
                temp[len++] = '0';
            }
            if(haaa[par].rchild == now){
                temp[len++] = '1';
            }
            now = par;
            par = haaa[now].parent;
        }
        ans[i] = (char*)malloc((len+1)*sizeof(char));
        for(int j = 0 ; j < len ; j++){
            ans[i][j] = temp[len - j - 1];
        }
        ans[i][len] = '\0';
    }

    return ans;
}