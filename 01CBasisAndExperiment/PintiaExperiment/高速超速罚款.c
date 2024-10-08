#include <stdio.h>

int main(){
	int rs, ss;
	scanf("%d%d",&rs, &ss);
	double rate = (ss-rs)*1.0 / rs;
	if (rate < 0.1) {
        printf("OK");
    } else if (rate >= 0.1 && rate < 0.5) {
        printf("Exceed %.0f%%. Ticket 200", rate * 100);
    } else if (rate >= 0.5) {
        printf("Exceed %.0f%%. License Revoked", rate * 100);
    }
	return 0;
} 
