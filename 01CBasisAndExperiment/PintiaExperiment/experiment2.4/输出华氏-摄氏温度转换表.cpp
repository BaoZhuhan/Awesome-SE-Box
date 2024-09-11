#include <stdio.h>

int main(void)
{
    int a=0,b=0;
    scanf("%d %d",&a,&b);
    if(((a<=b) && (b<=100))&& (a>=0))
    {
        printf("fahr celsius\n");
        for(int i =a;i<= b;i+=2)
        {
            printf("%d%-6.1f\n",i,(5*((float)i-32)/9));
        }
    }
    else
    {
        printf("Invalid.");
    }
    return 0;
}