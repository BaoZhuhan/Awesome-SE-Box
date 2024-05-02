#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char name[25];
    int sorce;
    int rank;
}node;

int cmp(const void *a,const void *b){
    node* pa = (node*)a;
    node* pb = (node*)b;
    
    if(pa->sorce != pb->sorce) {
        return (pa->sorce - pb->sorce < 0);
    }else{
        return (strcmp(pa->name,pb->name) > 0);
    }
}

int main(){
    int n ;
    scanf("%d",&n);
    getchar();

    node *a;
    a = (node*) malloc(n * sizeof(node));

    for(int i = 0 ; i < n ; i++){
        int j = 0 ;
        while((a[i].name[j] = getchar()) != ' '){
            j++;
        }
        a[i].name[j] = '\0';

        scanf("%d",&a[i].sorce);
        getchar();
    }

    qsort(a , n , sizeof(node) , cmp);

    a[0].rank = 1;

    for(int i = 1 ; i < n ; i++){
        if(a[i].sorce == a[i-1].sorce) a[i].rank = a[i-1].rank;
        else {
            a[i].rank = i + 1;
        } 
    }

    for(int i = 0 ; i < n ; i++){
        printf("%d %s\n",a[i].rank,a[i].name);
    }

    return 0;
}