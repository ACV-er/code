#include<stdio.h>

int a[105];

int gcd(int a, int b) {
    return b==0?a:gcd(b, a%b);
}

int main(void) {
    int N, n, i, j, m, b;
    scanf("%d", &N);
    while(N--) {
        b = m = 1;
        scanf("%d", &n);
        for(i=1; i<=n; i++) {
            scanf("%d", &a[i]);
        }
        for(i=1; i<=n; i++) {
        	b = 1;
            j = a[i];
            while(j!=i) {
                b++;
                j = a[j];
            }
            m = m/gcd(m, b)*b;
        }
        printf("%d\n", m);
    }

    return 0;
}
