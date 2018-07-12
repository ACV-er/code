#include<stdio.h>

int gcd(int a, int b) {
    int c;
    while(b != 0) {
        c = a%b;
        a = b;
        b = c;
    }

    return a;

}

int main(void) {
    int N, i, n, m, r;
    int a[4];
    scanf("%d", &N);
    while(N--) {
        for(i=0; i<4; i++) {
            scanf("%d", &a[i]);
        }
        m = a[1]*a[3]/gcd(a[1], a[3]);
        n = a[0]*(m/a[1]) + a[2]*(m/a[3]);
        if(n%m == 0) {
            printf("%d ", n/m);
        } else {
            r = gcd(n, m);
            printf("%d/%d ", n/r, m/r);
        }
        n = a[0]*(m/a[1]) - a[2]*(m/a[3]);
        if(n<0) {
            printf("-");
            n = -n;
        }
        if(n%m == 0) {
            printf("%d\n", n/m);
        } else {
            r = gcd(n, m);
            printf("%d/%d\n", n/r, m/r);
        }
    }

    return 0;
}
