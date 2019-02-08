#include<stdio.h>
#include<time.h>

int main(void) {
	int a, b, m, n, c;
	double time1, time2;
	scanf("%d %d", &a, &b);
	time1 = clock();
	m=b; c=1;
	while(m>0) {
		c *= a;
		c = c%10007; 
		m--;
	}
	time2 = clock();
	printf("?????%f???%d\n", time2-time1, c);
	n=a; m=b; c=1;
	while(m>0) {
		if(m&1) {
			c = c*n%10007;//??????????????? 
		}
		m >>= 1;
		n = n*n%10007;//?????????????????
	}
	time1 = clock();
	printf("??????%f???%d\n", time1-time2, c);
	
	
	return 0;
}