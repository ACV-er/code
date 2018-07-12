#include<stdio.h>
#include<time.h>

int num[1000001] = {0, 0, 1, 3, 8};
int pows[1000005] = {0, 0, 1, 2};

int main(void) {
    int i, j, N;
    for(i=3; i<=1000000; i++) {
        pows[i+1] = (pows[i]*2)%1000000007;
        num[i] = ( (num[i-2] + num[i-1])%1000000007 + pows[i] )%1000000007;
    }
    scanf("%d", &N);
    while(N--) {
        scanf("%d", &j);
        printf ("%d\n", num[j]);
    }


    return 0;
}
