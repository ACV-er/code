#include<stdio.h>
#include<time.h>

#define Radix 100000
#define DIG 5

int res[1001][514]={
    {1},{1},{2}
};

int main(void) {
    int i, j, N, m, n=1;
    for(i=3; i<1001; i++) {
        for(j=0; j<n; j++) {
            res[i][j] = res[i-1][j]*i;
        }
        for(j=0; j<n; j++) {
            if(res[i][j] >= Radix) {
                if( !(j+1-n) ) n = j+2;
                res[i][j+1] += res[i][j]/Radix;
                res[i][j] %= Radix;
            }
        }
    }
    scanf("%d", &N);
    while(N--) {
        scanf("%d %d", &i, &j);
        j--;
        m = j/DIG;
        j = j%DIG;
        n = res[i][m];
        while(j--) {
            n /= 10;
        }
        n %= 10;
        printf("%d\n", n);
    }

    return 0;
}
