#include <stdio.h>
#include <iostream>
using namespace std;
int main(void){
	int n,count =0 ;
	scanf("%d",&n);
	for(int i =0;i<n;i++){
		char a1,a2,a3,a4,a5,a6,a7,a8,a9,a0;
		count = 0;
		cin>>a1>>a2>>a3>>a4>>a5>>a6>>a7>>a8>>a9>>a0;
		if(a1=='c') count++;
		if(a2=='o') count++;
		if(a3=='d') count++;
		if(a4=='e') count++;
		if(a5=='f') count++;
		if(a6=='o') count++;
		if(a7=='r') count++;
		if(a8=='c') count++;
		if(a9=='e') count++;
		if(a0=='s') count++;
		count = 10-count;
		printf("%d\n",count);
	}
	return 0;
	
}