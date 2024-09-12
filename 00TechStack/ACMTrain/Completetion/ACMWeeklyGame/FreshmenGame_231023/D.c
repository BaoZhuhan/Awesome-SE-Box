#include <stdio.h>

int main(void){
	int n;
    int longth;
	scanf("%d",&n);
	for(int i=0;i<n;i++){

		scanf("%d",&longth);
		int a[longth],max=0,count=0;
		
		for(int j =0 ;j<longth;j++){
			scanf("%d",&a[j]);
			
			if (a[j] ==0) {
				count+=1;
				if(count>max) max = count;
			}
			else{
				count =0;
			}
		}
		printf("%d\n",max);


	}
	return 0;
}