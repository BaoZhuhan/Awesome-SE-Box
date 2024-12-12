#include <stdio.h>
int main(void){
	int n;
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		int num=0,flag=1;
		scanf("%d",&num);
		int a[num];
		for(int j=0;j<num;j++){
			scanf("%d",&a[j]);
		}
		for(int k=0;k<num-1;k++){
			for(int z=k+1;z<num;z++){
				if(a[k]==a[z]){
					flag =0;
					break;
				}
			}
		}
		if(flag ==1) printf("YES\n");
		else printf("NO\n");
		
	}
	return 0;
}