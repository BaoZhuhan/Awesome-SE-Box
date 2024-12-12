#include <stdlib.h>
#include <stdio.h>

#define leftchild(i) (2*(i)+1)

void PercDown(int A[], int i, int N){
    int child;
    int Tmp;

    for(Tmp = A[i];leftchild(i) < N;i = child){
        child = leftchild(i);
        if(){}
    }
}