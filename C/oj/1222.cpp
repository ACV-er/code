#include"stdio.h"

int main(void) {
    int N, i, A, B, now, time, j, maxn, I, J;
    int a[1000], b[1000];
    scanf("%d", &N);
    while(N--) {
        maxn = 0;
        now = 0;
        scanf("%d %d", &A, &B);
        for(i=0; i<A; i++) {
            scanf("%d", &a[i]);
        }
        for(i=0; i<B; i++) {
            scanf("%d", &b[i]);
        }
        j = A>B?B:A;
        for(i=0; i<j; i++) {
            now++;
            if( a[i]+b[i] > maxn ) {
                maxn = a[i]+b[i];
                time = now;
                I = i;
                J = i;
            }
        }
        if(i==A) i=0;
        if(j==B) j=0;
        while(i != j) {
            now++;
            if( a[i]+b[j] > maxn ) {
                maxn = a[i]+b[j];
                time = now;
                I = i;
                J = j;
            }
            if(++i == A) i=0;
            if(++j == B) j=0;
        }
        time--;
        printf("%d %d %d %d\n", time, maxn, a[I], b[J]);
    }

    return 0;
}
