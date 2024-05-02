#include<stdio.h>
#include<string.h>
#define MAXN 100
struct book
{
	char name[35];
	double price;
};
int main()
{
	struct book bo[MAXN];
	int n,max,min;
	max=0;
	min=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
        getchar();
        gets(bo[i].name);
		scanf("%lf",&bo[i].price);
		if(bo[i].price<bo[min].price)
		{
			min=i;
		}
		if(bo[i].price>bo[max].price)
		{
			max=i;
		}
		
	}
	printf("%.2lf, %s\n",bo[max].price,bo[max].name);
	printf("%.2lf, %s\n",bo[min].price,bo[min].name);
	return 0;
}