#include"stdio.h"

int main(void) {
    int N, i, maxn, coun;
    unsigned int n;
    scanf("%d", &N);
    while(N-- != 0) {
        scanf("%u", &n);
        maxn = 0, coun = 0;
        for (i=0; n != 0; i++) {
            if( (n&1) == 0) {
                if(maxn < coun) {
                    maxn = coun;
                }
                coun = 0;
            } else {
                coun++;
            }
            n >>= 1;
        }
        if(maxn < coun) maxn = coun;
        printf("%d\n", maxn);
    }

    return 0;
}
