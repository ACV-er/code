#include<stdio.h>

int main(void) {
    int fb[30] = {1,2};
    int i, N, num, n;
    for(i=2; i<30; i++) {
        fb[i] = fb[i-1] + fb[i-2];
    }
    scanf("%d", &N);
    while(N--) {
        scanf("%d", &n);
        for(i=29, num=0; i>=0; i--) {
            if(n >= fb[i]) {
                num += 1<<i;
                n -= fb[i];
            }
        }
        printf("%d\n", num);
    }
}
