#include <stdio.h>

int main(void){
	int n;
	scanf("%d",&n);
	for(int i =0;i<n;i++){
		int num=0,m=0,b=0;
		scanf("%d",&num);
		int a[num],flag=1;
		for(int j=0;j<num;j++){
			scanf("%d",&a[j]);
			if(a[j]%2==0) m+=a[j];
			else b+=a[j];	
		}
		if(b>=m) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}