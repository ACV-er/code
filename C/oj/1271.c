#include<stdio.h>

int main(void) {
	int N, n, m, k, i, j, flag, cnt, sum;
	scanf("%d", &N);
	while(N--) {
		sum = 0;
		int a[101][101] = {0};
		scanf("%d %d %d", &m, &n, &k);
		while(k--) {
			scanf("%d %d", &i, &j);
			a[i][j] = -1;
		}
		for(i=1; i<=m; i++) {
			flag = cnt = 0;
			for(j=1; j<=n; j++) {
				if(a[i][j] == -1) {
					flag = 1;
					break;
				} else {
					cnt += a[i][j];
				}
			}
			if(flag == 0) {
				sum+=n-cnt;
				for(j=1; j<=n; j++) {
					a[i][j] = 1;
				}
			}
		}
		for(i=1; i<=n; i++) {
			flag = cnt = 0;
			for(j=1; j<=m; j++) {
				if(a[j][i] == -1) {
					flag = 1;
					break;
				} else {
					cnt += a[j][i];
				}
			}
			if(flag == 0) {
				sum+=m-cnt;
				for(j=1; j<=m; j++) {
					a[j][i] = 1;
				}
			}
		}
		printf("%d\n", sum);
	}
	
	return 0; 
}
