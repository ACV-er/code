#include<stdio.h>

int main(void) {
    int N;
    scanf("%d", &N);
    __int64 num, a, b;
    while(N--) {
        scanf("%I64d %I64d", &a, &b);
        printf ("%I64d\n", (a)*(a-1)/2 + b );
    }

    return 0;
}
