#include<stdio.h>

int main(void) {
	int N, key;
	double may, need, nowMay;
	scanf("%d", &N);
	while(N--) {
		scanf("%lf %lf", &may, &need);
		key = 1;
		if( (may==0 && need != 0) || (need==100 && may != 100) || (need==0 && may != 0)) {
			printf("Impossible\n");
			continue;
		}
		nowMay = 100 - may;
		need = 100 - need;
		while(need<nowMay) {
			nowMay = nowMay*(100-may)/100;
			key++;
		}
		printf("%d\n", key);
		
	}
	
	return 0;
} 
