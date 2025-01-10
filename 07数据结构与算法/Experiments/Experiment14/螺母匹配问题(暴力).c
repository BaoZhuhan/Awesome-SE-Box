#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    double size;
    int bolt_loc;
} nut;

int main()
{
    int n;
    scanf("%d", &n);

    int *cask = calloc(10000000, sizeof(int));
    nut *nuts = calloc(n, sizeof(nut));

    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &nuts[i].size);
        cask[(int)(nuts[i].size * 1000)] = i;
    }

    for (int i = 0; i < n; i++)
    {
        double bolt;
        scanf("%lf", &bolt);
        (nuts + (cask[(int)(bolt * 1000)]))->bolt_loc = i;
    }

    for (int i = 0; i < n - 1; i++)
    {
        printf("%d ", nuts[i].bolt_loc);
    }
    printf("%d", nuts[n - 1].bolt_loc);
}